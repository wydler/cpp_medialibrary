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
#include "Utilities.h"

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
	std::cout << " ";
	std::cout << std::setw(6) << std::right << signature;
	std::cout << "  ";
	std::cout << std::setw(10) << std::left << type;
	std::cout << "  ";
	std::cout << std::setw(15) << std::left << title;
	std::cout << "  ";
	std::cout << std::setw(5) << std::left << printState();
	std::cout << "  ";
	std::cout << std::left << "Dauer " << std::setprecision(2) << std::fixed << lenght << " min" << std::endl;
}
