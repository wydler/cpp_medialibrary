/*
 * Medium.cpp
 *
 *  Created on: 05.04.2010
 *      Author: Michael Wydler
 */

#include "Medium.h"
#include <iostream>
#include <sstream>
#include <iomanip>

Medium::Medium() {
	std::cout << "Bitte Mediumdaten eingeben: Signatur und Titel" << std::endl;
	signature = inputSignature();
	title = inputTitle();
	type = "Medium";
	state = false;
}

Medium::~Medium() {
	// TODO Auto-generated destructor stub
}

/**
 * Convert the state from boolean into text.
 */
std::string Medium::printState() {
	if( state == false ) {
		return "vorh.";
	} else {
		return "entl.";
	}
}

/**
 * Print the current object.
 */
void Medium::print() {
	std::cout << " ";
	std::cout << std::setw(6) << std::right << signature;
	std::cout << "  ";
	std::cout << std::setw(10) << std::left << type;
	std::cout << "  ";
	std::cout << std::setw(15) << std::left << title;
	std::cout << "  ";
	std::cout << std::setw(5) << std::left << printState();
}

/**
 * Input new string.
 */
std::string Medium::inputTitle() {
	std::string s;
	std::cout << "Titel: ";
	std::cin.clear();
	std::cin.ignore( 999, '\n' );
	std::getline( std::cin, s );
	return s;
}

/**
 * Input signature and check validity.
 */
int Medium::inputSignature() {
	unsigned int signature = 0;
	std::cout << "Signatur eingeben: ";
	while( !(std::cin >> signature) ) {
		std::cin.clear();
		std::cin.ignore( 999, '\n' );
		std::cerr << "[ERROR] Keine gültige Signatur eingegeben!";
	}
	return signature;
}
