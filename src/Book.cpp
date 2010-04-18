/*
 * Book.cpp
 *
 *  Created on: 05.04.2010
 *      Author: Michael Wydler
 */

#include "Book.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Utilities.h"

Book::Book() : Medium(0) {
	std::cout << "Bitte Buchdaten eingeben: Signatur, Seitenzahl und Titel" << std::endl;
	signature = inputSignature();
	pages = inputPages();
	title = inputTitle();
	type = "Book";
	state = false;
}

Book::~Book() {
	// TODO Auto-generated destructor stub
}

/**
 * Print the current object.
 */
void Book::print() {
	std::cout << " ";
	std::cout << std::setw(6) << std::right << signature;
	std::cout << "  ";
	std::cout << std::setw(10) << std::left << type;
	std::cout << "  ";
	std::cout << std::setw(15) << std::left << title;
	std::cout << "  ";
	std::cout << std::setw(5) << std::left << printState();
	std::cout << "  ";
	std::cout << std::left << "Seitenanzahl " << pages << std::endl;
}
