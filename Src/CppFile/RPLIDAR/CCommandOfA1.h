/*
 * CCommandOfA1.h
 *
 *  Created on: 2019年9月5日
 *      Author: wyz
 */

#ifndef CPPFILE_RPLIDAR_CCOMMANDOFA1_H_
#define CPPFILE_RPLIDAR_CCOMMANDOFA1_H_

#include <CCommand.h>
#include "CReceiver.h"
#include <string>

namespace wyz {

class CCommandOfA1: public CCommand {
public:
	CCommandOfA1(CReceiver* pReceiver,std::string order);
	~CCommandOfA1();
	std::string GetOrder();
	void Excute(CCommand* pCommand);
	enum m_CommandType{SendOrder,GetAns,};
private:
	std::string m_Order;
};

} /* namespace wyz */

#endif /* CPPFILE_RPLIDAR_CCOMMANDOFA1_H_ */
