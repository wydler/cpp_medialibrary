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
#include <limits>

using namespace std;

Book::Book() : Medium(0) {
	std::cout << "  Bitte Buchdaten eingeben: Signatur, Seitenzahl und Titel" << std::endl;
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
 * Input pages and check validity.
 */
int Book::inputPages() {
	unsigned int pages = 0;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "  Seitenanzahl: ";
	while( !(cin >> pages) ) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cerr << "  [ERROR] Keine gültige Seitenzahl eingegeben!";
	}
	return pages;
}

string Book::getDetails() {
	stringstream string;
	string << right << pages << " Seiten";

	return string.str();
}
