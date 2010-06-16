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

StatusError::StatusError(string _title) {
	title = _title;
}

string StatusError::message() {
	ostringstream os;
	os << "  Fehler beim Leihen/Rueckgeben von \'" << title << "\'.";
	return os.str();
}

Medium::Medium() {
	cout << "  Bitte Mediumdaten eingeben: Signatur und Titel" << std::endl;
	signature = inputSignature();
	title = inputTitle();
	type = "Medium";
	state = praesent;
}

Medium::~Medium() {
	// TODO Auto-generated destructor stub
}

/**
 * Convert the state from boolean into text.
 */
std::string Medium::printState() {
	if( state == praesent ) {
		return "vorh.";
	} else {
		return "entl.";
	}
}

std::ostream &operator<<(std::ostream &ostr, Medium* item)
{
	return ostr << " "
			<< setw(8) << right << item->getSignature() << "   "
			<< setw(6) << left << item->getType() << "   "
			<< setw(20) << left << item->getTitle().substr(0, 20) << "   "
			<< setw(6) << left << item->printState() << "   "
			<< item->getDetails()
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

void Medium::printHead() {
	cout << " "
	<< setw(8) << right << "Signatur" << "   "
	<< setw(6) << left << "Typ" << "   "
	<< setw(20) << left << "Titel" << "   "
	<< setw(6) << left << "Status" << "   "
	<< "weitere Daten "
	<< endl;
}

void Medium::lendMedium() {
	if( state == praesent ) {
		state = entliehen;
		std::cout << "  " << type << " " << signature << " wurde als entliehen markiert." << std::endl;
	} else {
		throw StatusError(title);
	}
}

void Medium::returnMedium() {
	if( state == entliehen ) {
		state = praesent;
		std::cout << "  " << type << " " << signature << " wurde als vorhanden markiert." << std::endl;
	} else {
		throw StatusError(title);
	}
}
