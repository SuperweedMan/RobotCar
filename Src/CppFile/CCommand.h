/*
 * CCommand.h
 *
 *  Created on: 2019年9月5日
 *      Author: wyz
 */

#ifndef CPPFILE_CCOMMAND_H_
#define CPPFILE_CCOMMAND_H_
#include "CReceiver.h"

namespace wyz {

class CCommand {
public:
	CCommand();
	~CCommand();
	virtual void Excute(CCommand* pCommand) = 0;
protected:
	CReceiver* m_Receiver;
};

} /* namespace wyz */

#endif /* CPPFILE_CCOMMAND_H_ */
