/*
 * Utilities.cpp
 *
 *  Created on: 13.04.2010
 *      Author: Michael Wydler
 */

#include "Utilities.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

/**
 * Input new string.
 */
std::string inputTitle() {
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
int inputSignature() {
	unsigned int signature = 0;
	std::cout << "Signatur eingeben: ";
	while( !(std::cin >> signature) ) {
		std::cin.clear();
		std::cin.ignore( 999, '\n' );
		std::cerr << "[ERROR] Keine gültige Signatur eingegeben!";
	}
	return signature;
}

/**
 * Input pages and check validity.
 */
int inputPages() {
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

/**
 * Input lenght and check validity.
 */
double inputLenght() {
	double lenght = 0;
	std::cout << "Spieldauer: ";
	while( !(std::cin >> lenght) ) {
		std::cin.clear();
		std::cin.ignore( 999, '\n' );
		std::cerr << "[ERROR] Keine gültige Filmlänge eingegeben!";
	}
	return lenght;
}
