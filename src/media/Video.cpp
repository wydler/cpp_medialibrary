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

Video::Video() : Medium(0) {
	std::cout << "Bitte Buchdaten eingeben: Signatur, Spieldauer und Titel" << std::endl;
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
 * Print the current object.
 */
void Video::print() {
	Medium::print();
	std::cout << "  ";
	std::cout << std::left << "Dauer " << std::setprecision(2) << std::fixed << lenght << " min";
}

/**
 * Input lenght and check validity.
 */
double Video::inputLenght() {
	double lenght = 0;
	std::cout << "Spieldauer: ";
	while( !(std::cin >> lenght) ) {
		std::cin.clear();
		std::cin.ignore( 999, '\n' );
		std::cerr << "[ERROR] Keine gültige Filmlänge eingegeben!";
	}
	return lenght;
}
