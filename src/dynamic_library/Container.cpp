/*
 * Library.cpp
 *
 *  Created on: 07.04.2010
 *      Author: Michael Wydler
 */

#include "Container.h"

#include <algorithm>
#include <iostream>

Container::Container() {
	this->current = NULL;
	this->first = NULL;
	this->last = NULL;
}

Container::~Container() {
	// TODO Auto-generated destructor stub
}

/**
 * Add new element to library
 */
bool Container::add( ITEM* newItem ) {
	C_Element* newE = new C_Element();
	if(newE == NULL) { return false; };

	newE->item = newItem;
	newE->previous = this->last;
	newE->next = NULL;

	if(this->last != NULL) {
		this->last->next = newE;
	} else {
		this->first = newE;
	}
	this->last = newE;

	return true;
}

/**
 * Remove element from library
 */
bool Container::remove() {
	C_Element* curE = this->current;
	if(this->current == NULL) return false;

	this->current = curE->previous;
	if(this->current != NULL) {
		this->current->next = curE->next;
	} else {
		this->first = curE->next;
	}

	this->current = curE->next;
	if(this->current != NULL) {
		this->current->previous = curE->previous;
	} else {
		this->last = curE->previous;
	}

	delete curE;

	return true;
}

/**
 * Set first element as current element
 */
void Container::begin() {
	this->current = this->first;
}

/**
 * Get the next element
 */
void Container::next() {
	if(this->current != NULL) {
		this->current = this->current->next;
	}
}

/**
 * Return the current element
 */
ITEM* Container::getItem() {
	if(this->current != NULL) {
		return this->current->item;
	} else {
		return NULL;
	}
}
