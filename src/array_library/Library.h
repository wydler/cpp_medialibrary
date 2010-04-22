/*
 * Library.h
 *
 *  Created on: 07.04.2010
 *      Author: Michael Wydler
 */

#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <iostream>
#include "../media/Medium.h"
#include "../media/Book.h"
#include "../media/Video.h"

class Library {
	public:
		Library();
		virtual ~Library();
		void add( Medium* );
		void remove( Medium* );
		void changeState( bool );
		void print();
		void deleteAll();
		int getSize() { return MAX; };
	private:
		static const int MAX = 100;
		Medium* mediumLib[MAX];

};

#endif /* LIBRARY_H_ */
