/*
 * CCommandOfA1.cpp
 *
 *  Created on: 2019年9月5日
 *      Author: wyz
 */

#include <CCommandOfA1.h>

namespace wyz {

CCommandOfA1::CCommandOfA1(CReceiver* pReceiver,std::string order) {
	m_Receiver = pReceiver;
	this->m_Order = order;
}

CCommandOfA1::~CCommandOfA1() {
	// TODO Auto-generated destructor stub
}

std::string CCommandOfA1::GetOrder(){
	return this->m_Order;
}

void CCommandOfA1::Excute(CCommand* pCommand){
	m_Receiver->Action(this);
}


} /* namespace wyz */
