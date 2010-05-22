/*
 * Video.cpp
 *
 *  Created on: 05.04.2010
 *      Author: Michael Wydler
 */

#include "Video.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>

using namespace std;

Video::Video() : Medium(0) {
	cout << "  Bitte Buchdaten eingeben: Signatur, Spieldauer und Titel" << std::endl;
	signature = inputSignature();
	lenght = inputLenght();
	title = inputTitle();
	type = "Video";
	state = false;
}

Video::~Video() {
	// TODO Auto-generated destructor stub
}

/**
 * Input lenght and check validity.
 */
double Video::inputLenght() {
	double lenght = 0;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "  Spieldauer: ";
	while( !(cin >> lenght) ) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cerr << "  [ERROR] Keine gültige Filmlänge eingegeben!";
	}
	return lenght;
}

string Video::getDetails() {
	stringstream string;
	string << "Spieldauer: " << fixed << setprecision(2) << getLenght() << " min.";

	return string.str();
}
