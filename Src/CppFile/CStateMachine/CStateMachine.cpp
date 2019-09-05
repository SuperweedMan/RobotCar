/*
 * CStateMachine.cpp
 *
 *  Created on: 2019年9月4日
 *      Author: wyz
 */
#include "CStateMachine.h"

namespace wyz{

int64_t CStateMachine::MergeIntToLong(int value_1,int value_2)
{
	union mergeUnion
	{
		int64_t INT64_t;
		struct LowHigh{
			int lowInt;
			int highInt;
		}lowhigh;
	} mergeUnion;
	mergeUnion.lowhigh.lowInt = value_1;
	mergeUnion.lowhigh.highInt = value_2;
	return mergeUnion.INT64_t;
}

void CStateMachine::AddItemOfInternalTransitions(int eventType,int state,int newStats)
{
	m_IntranalTransitions[MergeIntToLong(eventType, state)] = newStats;
}

void CStateMachine::AddItemOfStateMap(int state,CStateBase * pStateAction)
{
	m_StateMap[state] = pStateAction;
}

void CStateMachine::AddItemOfTransitions(int eventType,int state, int newStats)
{
	m_Transitions[MergeIntToLong(eventType, state)] = newStats;
}

void CStateMachine::SetEvent(CMachineEventBase* pEvent)
{
	ExternalEvent(pEvent, pEvent->m_ExternalEventType);
}

void CStateMachine::InternalEvent(CMachineEventBase *pData)
{
	int64_t merge = MergeIntToLong(pData->m_InternalEventType, m_CurrentState);
	if (m_IntranalTransitions.count(merge)!=0) {
		m_NewState = m_IntranalTransitions[merge];
		if(m_StateMap.count(m_NewState) != 0)
		{   //存在状态函数
			CStateBase *pState = m_StateMap[m_NewState];
			pState->InvokeStateAction(this, pData);
			m_CurrentState = m_NewState;
		}
	}
	if(m_IntranalTransitions.count(MergeIntToLong(pData->m_InternalEventType, m_CurrentState))!=0)
	{InternalEvent(pData);}//迭代，直到没有状态转移
}

void CStateMachine::ExternalEvent(CMachineEventBase * pData,int EventType)
{
	m_TransitionsItem = m_Transitions.find(MergeIntToLong(EventType, m_CurrentState));
	if(m_TransitionsItem != m_Transitions.end())
	{   //存在状态转移
		m_NewState = m_TransitionsItem->second;
		if(m_StateMap.count(m_NewState) != 0)
		{   //存在状态函数
			CStateBase *pState = m_StateMap[m_NewState];
			pState->InvokeStateAction(this, pData); //这个过程中可以更新内部事件
			m_CurrentState = m_NewState;
			InternalEvent(pData); //调用内部事件
		}
	}
}


}


