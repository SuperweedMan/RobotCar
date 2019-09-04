/*
 * CUart.cpp
 *
 *  Created on: 2019年7月22日
 *      Author: wyz
 */

#include "CUart.h"
#include "CRelateOfHandleAndCUart.h"
#include "main.h"


void HAL_UART_RxCpltCallback(UART_HandleTypeDef  *huart){
	if(wyz::CRelateOfHandleAndCUart::GetInstance()->Exists(huart)){
		if(wyz::CRelateOfHandleAndCUart::GetInstance()->Get(huart)->GetUartMode() == wyz::CUart::m_ObserverMode){
			wyz::CRelateOfHandleAndCUart::GetInstance()->Get(huart)->HardInterrupt(wyz::CUart::m_UART_RxCplt);
		}
	}
}

void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart){
	if(wyz::CRelateOfHandleAndCUart::GetInstance()->Exists(huart)){
		if(wyz::CRelateOfHandleAndCUart::GetInstance()->Get(huart)->GetUartMode() == wyz::CUart::m_ObserverMode){
					wyz::CRelateOfHandleAndCUart::GetInstance()->Get(huart)->HardInterrupt(wyz::CUart::m_UART_RxHalfCplt);
				}
		}
}

namespace wyz {

CUart::CUart(UART_HandleTypeDef *huart,uint32_t SizeOfRxBuf,uint32_t SizeOfTxBuf,uint8_t Mode ) {
	// TODO Auto-generated constructor stubthis
	this->m_Huart=huart;
	this->m_SizeOfRxBuf=SizeOfRxBuf;
	this->m_SizeOfTxBuf=SizeOfTxBuf;
	this->m_pRxBuf= new uint8_t[SizeOfRxBuf*2]; //读缓存,*2好用双缓存模式
	this->m_pTxBuf =new uint8_t[SizeOfTxBuf];
	m_UartMode=Mode;
	CRelateOfHandleAndCUart::GetInstance()->Add(this, huart);
}
CUart::~CUart() {
	// TODO Auto-generated destructor stub
	delete[] this->m_pRxBuf;
	delete[] this->m_pTxBuf;
};


/*******************************************/
uint8_t CUart::Open()
{
	return 0;
}
uint8_t CUart::Close()
{
	return 0;
}

uint32_t CUart::GetSizeOfRxBuf()
{
	return this->m_SizeOfRxBuf;
}

uint8_t* CUart::GetPointOfRxBuf()
{
	if(this->m_InterruptMode == m_UART_RxCplt)
	{
		return this->m_pRxBuf+this->m_SizeOfRxBuf;
	}
	else
	{
		return this->m_pRxBuf;
	}
}
void CUart::BlockRead(uint8_t* pDataBuf,uint32_t Size,uint32_t TimeOut)
{
	HAL_UART_Receive(this->m_Huart,pDataBuf,Size,TimeOut);
}

void CUart::Blockwrite(uint8_t* pDataBuf,uint32_t Size,uint32_t TimeOut)
{
	HAL_UART_Transmit(this->m_Huart,pDataBuf,Size,TimeOut);
}

void CUart::NonBlockRead(uint8_t* pDataBuf,uint32_t Size,uint32_t TimeOut)
{
    if(m_UartMode == m_UsingDMAMode)
    {
    	HAL_UART_Receive_DMA(this->m_Huart,pDataBuf,Size);
    }
    else if(m_UartMode == m_UsingITMode)
    {
    	HAL_UART_Receive_IT(this->m_Huart,pDataBuf,Size);
    }else if(m_UartMode == m_UsingBlockMode)
    {
    	//配置错误
    }
}

void CUart::NonBlockWrite(uint8_t* pDataBuf,uint32_t Size,uint32_t TimeOut)
{
	 if(m_UartMode == m_UsingDMAMode)
	 {
		 HAL_UART_Transmit_DMA(this->m_Huart,pDataBuf,Size);
	 }
	 else if(m_UartMode == m_UsingITMode)
	 {
	 	 HAL_UART_Transmit_IT(this->m_Huart,pDataBuf,Size);
	 }else if(m_UartMode == m_UsingBlockMode)
	 {
	 	//配置错误
	 }
}
/************************************************/
void CUart::Attach(CObserver* pObserver)
{
	m_ObserverList.push_back(pObserver);
	StartObserverMode();
}

void CUart::Detach(CObserver* pObserver)
{
	m_ObserverList.remove(pObserver);
}

void CUart::Notify()
{

	list<CObserver*>::iterator item = m_ObserverList.begin();
	while(item != m_ObserverList.end())
	{
		(*item)->Update(this);
		++item;
	}
}

void CUart::StartObserverMode()
{
	HAL_UART_Receive_DMA(this->m_Huart,m_pRxBuf,this->m_SizeOfRxBuf*2);
}
/*****************************************************/
void CUart::HardInterrupt(uint8_t interruptMode)
{
	this->m_InterruptMode = interruptMode;
	this->Notify();
}

int CUart::GetUartMode(){
	return this->m_UartMode;
}

} /* namespace wyz */


