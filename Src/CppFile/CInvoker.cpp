/*
 * CInvoker.cpp
 *
 *  Created on: 2019年9月5日
 *      Author: wyz
 */

#include <CInvoker.h>

namespace wyz {

CInvoker::CInvoker() {
	// TODO Auto-generated constructor stub

}

CInvoker::~CInvoker() {
	// TODO Auto-generated destructor stub
}

void CInvoker::setCommand(CCommand* pCommand){
	m_CmdList.push_back(pCommand);
}

void CInvoker::cancleCommand(CCommand* pCommand){
	m_CmdList.remove(pCommand);
}

void CInvoker::excuteCommand(){
	std::list<CCommand*>::iterator item = m_CmdList.begin();
	while(item != m_CmdList.end()){
		(*item)->Excute(*item);
		item++;
	}
}



} /* namespace wyz */
