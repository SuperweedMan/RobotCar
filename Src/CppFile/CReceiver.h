/*
 * CReceiver.h
 *
 *  Created on: 2019年9月5日
 *      Author: wyz
 */

#ifndef CPPFILE_CRECEIVER_H_
#define CPPFILE_CRECEIVER_H_

namespace wyz {

class CCommand;
class CReceiver {
public:
	CReceiver();
	~CReceiver();
	virtual void Action(CCommand* pCommand) = 0;
};

} /* namespace wyz */

#endif /* CPPFILE_CRECEIVER_H_ */
