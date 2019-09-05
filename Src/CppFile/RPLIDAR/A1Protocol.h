/*
 * A1Protocol.h
 *
 *  Created on: Sep 3, 2019
 *      Author: wyz
 */

#ifndef CPPFILE_RPLIDAR_A1PROTOCOL_H_
#define CPPFILE_RPLIDAR_A1PROTOCOL_H_
#include "CObserver.h"
#include "CMachineEventBase.h"
#include "CStateBase.h"
#include "CStateMachine.h"
#include "CStateAction.h"
#include "CCommandOfA1.h"
#include "CReceiver.h"
#include "CInvoker.h"
#include "CUart.h"
#include <string>
namespace wyz {

class CA1_Event : public CMachineEventBase{
public:
	CA1_Event(int ExternalEventType,int internalEventType = 0,std::string order = ""){
		this->m_ExternalEventType = ExternalEventType;
		this->m_InternalEventType = internalEventType;
		this->m_Order = order;
	};
	~CA1_Event(){};
private:
	std::string m_Order;
};


class A1_Protocol :public CObserver,public CStateMachine{
public:
	A1_Protocol(CDevice * pDevice);
	~A1_Protocol();
	/*********Observer***********/

	void Update(CSubject* pSubject){

		CA1_Event *pEvent = new CA1_Event(ExternalEventType::AFrameOfData);
		this->SetEvent(pEvent);
		delete pEvent;
	}
	/**********statemachine*****************/
	enum ExternalEventType{
		DoNothing,
		StartSignal,
		AFrameOfData,
	};
	enum CA1Stats{
		BeginState,
		WaitForAns,
		WhetherTheFault,
		WaitForInitialAns,
		WaitForData,
		IdleState,
		ErrorState,
		AnalyticalState,
	};

	void ST_BeginState(CA1_Event* pEvent);
	CStateAction<A1_Protocol,CA1_Event,&A1_Protocol::ST_BeginState> STA_begin;
	void ST_WaitForAns(CA1_Event* pEvent);
	CStateAction<A1_Protocol,CA1_Event,&A1_Protocol::ST_WaitForAns> STA_waitForAns;
	void ST_WhetherTheFault(CA1_Event* pEvent);
	CStateAction<A1_Protocol,CA1_Event,&A1_Protocol::ST_WhetherTheFault> STA_whetherTheFault;
	void ST_WaitForInitialAns(CA1_Event* pEvent);
	CStateAction<A1_Protocol,CA1_Event,&A1_Protocol::ST_WaitForInitialAns> STA_waitForInitialAns;
	void ST_WaitForData(CA1_Event* pEvent);
	CStateAction<A1_Protocol,CA1_Event,&A1_Protocol::ST_WaitForData> STA_waitForData;
	void ST_IdleState(CA1_Event* pEvent);
	CStateAction<A1_Protocol,CA1_Event,&A1_Protocol::ST_IdleState> STA_idleState;
	void ST_ErrorState(CA1_Event* pEvent);
	CStateAction<A1_Protocol,CA1_Event,&A1_Protocol::ST_ErrorState> STA_errorState;
	void ST_AnalyticalState(CA1_Event* pEvent);
	CStateAction<A1_Protocol,CA1_Event,&A1_Protocol::ST_AnalyticalState> STA_analyticalState;

private:
	CInvoker* m_pInvoker;
	CDevice* m_pDevice;
	enum InternalEventType{
		DoNothing_In,
		Reset,
		GoAhead,
	};
};





} /* namespace wyz */

#endif /* CPPFILE_RPLIDAR_A1PROTOCOL_H_ */
