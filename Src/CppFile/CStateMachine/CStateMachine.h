/*
 * CStateMachine.h
 *
 *  Created on: 2019年8月20日
 *      Author: wyz
 */

#ifndef CLASS_CSTATEMACHINE_CSTATEMACHINE_H_
#define CLASS_CSTATEMACHINE_CSTATEMACHINE_H_
#include <map>
#include <vector>
#include "CMachineEventBase.h"
#include "CStateAction.h"
#include "CStateBase.h"

namespace wyz {

class CStateMachine {
public:
	virtual ~CStateMachine() {};
	void SetEvent(CMachineEventBase* pEvent);
	int GetCurrentState(){return this->m_CurrentState;}
protected:
	void AddItemOfStateMap(int state,CStateBase * pStateAction);
	void AddItemOfTransitions(int eventType,int state,int newStats);
	void AddItemOfInternalTransitions(int eventType,int state,int newStats);
	void ExternalEvent(CMachineEventBase * pData,int EventType);
	void InternalEvent(CMachineEventBase * pData);
	void SetCurrentState(int state){this->m_CurrentState = state;}
private:
	std::map<int,CStateBase*> m_StateMap; //map<state,CStateBase*>
	std::map<int64_t ,int > m_IntranalTransitions;
	std::map<int64_t ,int > m_Transitions;//map<CEventType and currentState,vector<newState>>
	std::map<int64_t,int>::iterator m_TransitionsItem;
	int m_CurrentState = 0;
	int m_NewState = 0;
	int64_t MergeIntToLong(int value_1,int value_2);
};


}  // namespace wyz
#endif /* CLASS_CSTATEMACHINE_CSTATEMACHINE_H_ */
