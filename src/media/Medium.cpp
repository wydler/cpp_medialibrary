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
#include <limits>

using namespace std;

Medium::Medium() {
	cout << "  Bitte Mediumdaten eingeben: Signatur und Titel" << std::endl;
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

std::ostream &operator<<(std::ostream &ostr, Medium* item)
{
	return ostr << " "
			<< setw(6) << right << item->getSignature() << " "
			<< setw(10) << left << item->getType() << " "
			<< setw(10) << left << item->getTitle().substr(0, 10) << " "
			<< setw(5) << left << item->printState() << " "
			<< item->getDetails() << " "
			<< endl;
}

/**
 * Input new string.
 */
std::string Medium::inputTitle() {
	string s;
	cout << "  Titel: ";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(std::cin, s);
	return s;
}

/**
 * Input signature and check validity.
 */
int Medium::inputSignature() {
	unsigned int sig = 0;
	cout << "  Signatur eingeben: ";
	while( !(cin >> sig) ) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cerr << "  [ERROR] Keine gültige Signatur eingegeben!";
	}
	return sig;
}
