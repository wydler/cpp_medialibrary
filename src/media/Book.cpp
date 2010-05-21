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
	Medium::print();
	std::cout << "  ";
	std::cout << std::left << "Seitenanzahl " << pages;
}

std::ostream &operator<<(std::ostream &ostr, Book* item)
{
	return ostr << " "
			<< std::setw(6) << std::right << item->getSignature() << " "
			<< std::setw(10) << std::left << item->getType() << " "
			<< std::setw(15) << std::left << item->getTitle() << " "
			<< std::setw(5) << std::left << item->printState() << " "
			<< std::left << "Seitenanzahl " << item->getPages() << " "
			<< std::endl;
}

/**
 * Input pages and check validity.
 */
int Book::inputPages() {
	unsigned int pages = 0;
	std::cin.clear();
	std::cin.sync();
	std::cin.ignore();
	std::cout << "Seitenanzahl: ";
	while( !(std::cin >> pages) ) {
		std::cin.clear();
		std::cin.ignore( 999, '\n' );
		std::cerr << "[ERROR] Keine gültige Seitenzahl eingegeben!";
	}
	return pages;
}
