/*
 * Medialibrary.cpp
 *
 *  Created on: 05.04.2010
 *      Author: Michael Wydler
 */

#include <iomanip>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include "Medium.h"
#include "Book.h"
#include "Video.h"
#include "Library.h"
#include "Utilities.h"
using namespace std;

int main() {
	char action;
	Library* lib = new Library();

	while( action != 'q' ) {
		cout << endl;
		cout << "Bitte Aktion eingeben: ";
		cin >> action;
		cout << endl;

		switch( action ) {
			case 'm': {
				Medium* m = new Medium();
				lib->add( m );
				break;
			}
			case 'b': {
				Book* b = new Book();
				lib->add( b );
				break;
			}
			case 'v': {
				Video* v = new Video();
				lib->add( v );
				break;
			}
			case 'l': {
				lib->print();
				break;
			}
			case 'e': {
				lib->changeState( true );

				break;
			}
			case 'r': {
				lib->changeState( false );

				break;
			}
			case 'h': {
				cout << "Mögliche Befehle:" << endl;
				cout << "m - Neues Medium anlegen" << endl;
				cout << "b - Neues Buch anlegen" << endl;
				cout << "v - Neues Video anlegen" << endl;
				cout << "l - Medienliste anzeigen" << endl;
				cout << "e SIG - Medium mit der Signatur 'SIG' ausleihen" << endl;
				cout << "r SIG - Medium mit der Signatur 'SIG' zurückgeben" << endl;
				cout << "h - Hilfe anzeigen" << endl;
				cout << "q - Programm beenden" << endl;
				break;
			}
			case 'q': {
				delete lib;
				cout << "[INFO]  Programm wurde beendet!" << endl;
				break;
			}
			default: {
				cin.clear();
				cin.ignore( 999, '\n' );
				cerr << "[ERROR] Keine gültige Aktion eingeben!" << endl;
				break;
			}
		}
	}

	return 0;
}
