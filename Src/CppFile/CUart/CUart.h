/*
 * CUart.h
 *
 *  Created on: 2019年7月22日
 *      Author: wyz
 */

#ifndef CLASS_CUART_H_
#define CLASS_CUART_H_
#include "CSubject.h"
#include "CDevice.h"
#include <list>
#include <map>

namespace wyz {



class CUart: public CDevice ,public CSubject{
private:
	UART_HandleTypeDef *m_Huart; //串口句柄
	uint32_t m_SizeOfRxBuf; //串口接收缓存大小
	uint32_t m_SizeOfTxBuf; //串口发送缓存大小
	uint8_t *m_pRxBuf;
	uint8_t *m_pTxBuf;
    uint8_t m_UartMode;
    list<CObserver*> m_ObserverList; //观察者列表
    uint8_t m_InterruptMode = m_UART_RxHalfCplt;
    void StartObserverMode();
public:
//#define m_UsingBlockMode 0
//#define m_UsingDMAMode   1 //非堵塞标志位
//#define m_UsingITMode    2
//#define m_ObserverMode   3
    enum{m_UsingBlockMode =0,m_UsingDMAMode,m_UsingITMode,m_ObserverMode};
//#define m_NonBlockReadInterrupt 0
//#define m_GetOneCharInterrupt   1
    enum{m_NonBlockReadInterrupt=0,m_GetOneCharInterrupt,};
    enum{m_UART_RxHalfCplt=0,m_UART_RxCplt,};
    int GetUartMode();
	CUart(UART_HandleTypeDef *huart,uint32_t SizeOfRxBuf=100,uint32_t SizeOfTxBuf=20,uint8_t kMode = m_UsingBlockMode) ;
	~CUart();
	uint32_t GetSizeOfRxBuf();
	uint8_t* GetPointOfRxBuf();
	/*用户中断函数*/
	void HardInterrupt(uint8_t interruptMode);

	/*************继承自CDevice*******************/
	uint8_t Open();
	uint8_t Close();
	void BlockRead(uint8_t *pDataBuf,uint32_t Size,uint32_t TimeOut=200);
	void Blockwrite(uint8_t *pDataBuf,uint32_t Size,uint32_t TimeOut=200);
	void NonBlockRead(uint8_t *pDataBuf,uint32_t Size,uint32_t TimeOut=0);
	void NonBlockWrite(uint8_t *pDataBuf,uint32_t Size,uint32_t TimeOut=0);
	/*************继承自CSubject*********************/
	void Attach(CObserver* pObserver);
	void Detach(CObserver* pObserver);
	void Notify();



};


} /* namespace wyz */

void HAL_UART_RxCpltCallback(UART_HandleTypeDef  *huart);

 void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart);

#endif /* CLASS_CUART_H_ */
