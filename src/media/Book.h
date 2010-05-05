/*
 * Book.h
 *
 *  Created on: 05.04.2010
 *      Author: Michael Wydler
 */

#ifndef BOOK_H_
#define BOOK_H_

#include <string>
#include "Medium.h"

class Book : public Medium {
public:
	Book();
	virtual ~Book();
	unsigned int getPages() { return pages; };
	void setPages( unsigned int _pages ) { pages = _pages; };
	virtual void print();
private:
	int inputPages();
	unsigned int pages;
};

#endif /* BOOK_H_ */
