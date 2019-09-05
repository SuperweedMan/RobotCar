/*
 * CInvoker.h
 *
 *  Created on: 2019年9月5日
 *      Author: wyz
 */

#ifndef CPPFILE_CINVOKER_H_
#define CPPFILE_CINVOKER_H_
#include <list>
#include "CCommand.h"

namespace wyz {

class CInvoker {
public:
	CInvoker();
	~CInvoker();
	void setCommand(CCommand *pcommand);
	void cancleCommand(CCommand *pcommand);
	void excuteCommand();
private:
	std::list<CCommand*> m_CmdList;
};

} /* namespace wyz */

#endif /* CPPFILE_CINVOKER_H_ */
