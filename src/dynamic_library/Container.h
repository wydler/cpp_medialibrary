/*
 * Library.h
 *
 *  Created on: 07.04.2010
 *      Author: Michael Wydler
 */

#ifndef CONTAINER_H_
#define CONTAINER_H_

#include <iostream>
#include "../media/Medium.h"
#include "../media/Book.h"
#include "../media/Video.h"

typedef Medium ITEM;

class C_Element {
	ITEM* item;
	struct C_Element* previous;
	struct C_Element* next;
	friend class Container;
};

class Container {
	public:
		Container();
		virtual ~Container();
		bool add(ITEM* item);
		bool remove();
		void begin();
		void next();
		ITEM* getItem();
	protected:
		C_Element* first;
		C_Element* current;
		C_Element* last;
};

#endif /* CONTAINER_H_ */
