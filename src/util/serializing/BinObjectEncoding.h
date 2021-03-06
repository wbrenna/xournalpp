/*
 * Xournal++
 *
 * Binary encoded serialized stream
 *
 * @author Xournal Team
 * http://xournal.sf.net
 *
 * @license GPL
 */

#ifndef __BINOBJECTENCODING_H__
#define __BINOBJECTENCODING_H__

#include "ObjectEncoding.h"

class BinObjectEncoding: public ObjectEncoding {
public:
	BinObjectEncoding();
	virtual ~BinObjectEncoding();

public:
	virtual void addData(const void * data, int len);

private:
	XOJ_TYPE_ATTRIB;
};

#endif /* __BINOBJECTENCODING_H__ */
