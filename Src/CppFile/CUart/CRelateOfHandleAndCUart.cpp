/*
 * CRelateOfHandleAndCUart.cpp
 *
 *  Created on: 2019年9月4日
 *      Author: wyz
 */

#include <CRelateOfHandleAndCUart.h>

namespace wyz {

CRelateOfHandleAndCUart::CRelateOfHandleAndCUart() {
	// TODO Auto-generated constructor stub

}

CRelateOfHandleAndCUart::~CRelateOfHandleAndCUart() {
	// TODO Auto-generated destructor stub
}

void CRelateOfHandleAndCUart::Add(CUart* pUart,UART_HandleTypeDef* pHandle){
	this->m_HandleMap[pHandle] = pUart;
}

bool CRelateOfHandleAndCUart::Exists(UART_HandleTypeDef* pHandle){
	return this->m_HandleMap.count(pHandle);
}

CUart* CRelateOfHandleAndCUart::Get(UART_HandleTypeDef* pHandle){
	if (this->m_HandleMap.count(pHandle)) {
		return this->m_HandleMap[pHandle];
	}else{
		return NULL;
	}
}

CRelateOfHandleAndCUart* CRelateOfHandleAndCUart::m_pInstance = new CRelateOfHandleAndCUart();

} /* namespace wyz */
