/*
 * Library.cpp
 *
 *  Created on: 07.04.2010
 *      Author: Michael Wydler
 */

#include "Library.h"

#include <algorithm>
#include <iostream>

Library::Library() {
	// TODO Auto-generated constructor stub
}

Library::~Library() {
	// TODO Auto-generated destructor stub
}

void Library::add( Medium* medium ) {
	bool s;

	for( unsigned int i = 0; i < ( sizeof( mediumLib ) / sizeof( mediumLib[0] ) ); i++ ) {
		if( mediumLib[i] == NULL ) {
			mediumLib[i] = medium;
			s = true;
			break;
		}
	}

	if( s == false ) {
		delete medium;
		std::cerr << "[ERROR] Arrayspeicher voll! Objekt wurde nicht gespeichert." << std::endl;
		std::flush(std::cerr);
	}
}

void Library::remove( Medium* medium ) {
	// TODO complete function Library::remove()
}

void Library::changeState( bool state ) {
	int flag = 0;
	unsigned int tmpSig = 0;

	std::cin >> tmpSig;

	for( unsigned int i = 0; i < (sizeof(mediumLib)/sizeof(mediumLib[0])) && mediumLib[i] != NULL; i++ ) {
		if( mediumLib[i]->getSignature() == tmpSig ) {
			if( mediumLib[i]->getState() == !state ) {
				mediumLib[i]->setState(state);
				if( mediumLib[i]->getState() == true ) {
					std::cout << mediumLib[i]->getType() << " " << mediumLib[i]->getSignature() << " wurde als entliehen markiert." << std::endl;
				} else {
					std::cout << mediumLib[i]->getType() << " " << mediumLib[i]->getSignature() << " wurde als vorhanden markiert." << std::endl;
				}
			}
			flag++;
		}
	}

	if( flag == 0 ) {
		std::cerr << "[ERROR] Signatur " << tmpSig << " existiert nicht!" << std::endl;
	}
}

void Library::print() {
	// TODO replace function with "cout" operation overloading
	std::cout << "MEDIENBESTAND" << std::endl;
	std::cout << "----------------------------------------------------------------------" << std::endl;

	for( unsigned int i = 0; i < (sizeof(mediumLib)/sizeof(mediumLib[0])) && mediumLib[i] != NULL; i++ ) {
		mediumLib[i]->print();
	}
}
