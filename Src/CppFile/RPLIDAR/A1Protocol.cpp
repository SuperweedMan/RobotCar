/*
 * A1Protocol.cpp
 *
 *  Created on: Sep 3, 2019
 *      Author: wyz
 */

//#include <RPLIDAR/A1Protocol.h>
#include "A1Protocol.h"
#include <vector>
namespace wyz {

A1_Protocol::A1_Protocol(CDevice* pDevice) {
	//绑定状态函数
	this->AddItemOfStateMap(CA1Stats::BeginState, &STA_begin);
	this->AddItemOfStateMap(CA1Stats::ErrorState, &STA_errorState);
	this->AddItemOfStateMap(CA1Stats::IdleState, &STA_idleState);
	this->AddItemOfStateMap(CA1Stats::WaitForData, &STA_waitForData);
	this->AddItemOfStateMap(CA1Stats::WaitForAns, &STA_waitForAns);
	this->AddItemOfStateMap(CA1Stats::WaitForInitialAns, &STA_waitForInitialAns);
	this->AddItemOfStateMap(CA1Stats::WhetherTheFault, &STA_whetherTheFault);
	this->AddItemOfStateMap(CA1Stats::AnalyticalState, &STA_analyticalState);
	//填充外部事件转移表
	this->AddItemOfTransitions(ExternalEventType::StartSignal, CA1Stats::IdleState, CA1Stats::BeginState);
	this->AddItemOfTransitions(ExternalEventType::AFrameOfData, CA1Stats::WaitForData,  CA1Stats::AnalyticalState);
	//填充内部事件转移表
	this->AddItemOfInternalTransitions(InternalEventType::GoAhead, CA1Stats::BeginState, CA1Stats::WaitForAns);
	//初始化状态
	this->SetCurrentState(CA1Stats::IdleState); //第一个状态
	this->m_pDevice = pDevice;
//	this->m_pInvoker = new CInvoker();
}

A1_Protocol::~A1_Protocol() {
//	delete this->m_pInvoker;
}


/****************observer*******************/


/***********StateAction****************/
void A1_Protocol::ST_BeginState(CA1_Event* pEvent){
	//发送GetHeath请求;
	uint8_t order[2]={0xa5 ,0x52};
	this->m_pDevice->ClearWriteFIFO();
	this->m_pDevice->Blockwrite(order, 2, 1000); //发送GET_HEALTH
	pEvent->m_InternalEventType =InternalEventType::GoAhead; //更新内部事件
}

void A1_Protocol::ST_WaitForAns(CA1_Event* pEvent){
	uint8_t databuf[10];
	m_pDevice->BlockRead(databuf, 10, 1000);
}

void A1_Protocol::ST_ErrorState(CA1_Event* pEvent){

}

void A1_Protocol::ST_IdleState(CA1_Event* pEvent){
	;
}

void A1_Protocol::ST_WaitForData(CA1_Event* pEvent){

}

void A1_Protocol::ST_WaitForInitialAns(CA1_Event* pEvent){

}

void A1_Protocol::ST_WhetherTheFault(CA1_Event* pEvent){

}

void A1_Protocol::ST_AnalyticalState(CA1_Event* pEvent){

}


} /* namespace wyz */
