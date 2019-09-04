/*
 * CRelateOfHandleAndCUart.h
 *
 *  Created on: 2019年9月4日
 *      Author: wyz
 */

#ifndef CPPFILE_CUART_CRELATEOFHANDLEANDCUART_H_
#define CPPFILE_CUART_CRELATEOFHANDLEANDCUART_H_
#include "CUart.h"
#include "main.h"
#include <map>
namespace wyz {

class CRelateOfHandleAndCUart {
public:
	static  CRelateOfHandleAndCUart* GetInstance(){
		return m_pInstance;
	}
	void Add(CUart* pUart,UART_HandleTypeDef* pHandle);
	CUart* Get(UART_HandleTypeDef* pHandle);
	bool Exists(UART_HandleTypeDef* pHandle);
private:
	static  CRelateOfHandleAndCUart* m_pInstance;
	std::map<UART_HandleTypeDef*,CUart*> m_HandleMap;
	CRelateOfHandleAndCUart();
	~CRelateOfHandleAndCUart();
};

} /* namespace wyz */

#endif /* CPPFILE_CUART_CRELATEOFHANDLEANDCUART_H_ */
