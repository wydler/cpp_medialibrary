/*
 * Medialibrary.cpp
 *
 *  Created on: 05.04.2010
 *      Author: Michael Wydler
 */

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>

#include "media/Medium.h"
#include "media/Book.h"
#include "media/Video.h"
#include "array_library/Library.h"

using namespace std;

int main() {
	// create variable for action
	char action;

	// create new library
	Library* lib = new Library();

	while( action != 'q' ) {
		// input new action
		cout << endl;
		cout << "Bitte Aktion eingeben: ";
		cin >> action;
		cout << endl;

		// switch to desired action
		switch( action ) {
			// create medium
			case 'm': {
				lib->add( new Medium() );
				break;
			}
			// create book
			case 'b': {
				lib->add( new Book() );
				break;
			}
			// create video
			case 'v': {
				lib->add( new Video() );
				break;
			}
			// print library-list
			case 'l': {
				lib->print();
				break;
			}
			// remove medium
			case 'd': {
				lib->remove();
				break;
			}
			// borrow a medium
			case 'e': {
				lib->changeState( true );
				break;
			}
			// return a medium
			case 'r': {
				lib->changeState( false );
				break;
			}
			// show help
			case 'h': {
				cout << "Mögliche Befehle:" << endl;
				cout << "m - Neues Medium anlegen" << endl;
				cout << "b - Neues Buch anlegen" << endl;
				cout << "v - Neues Video anlegen" << endl;
				cout << "l - Medienliste anzeigen" << endl;
				cout << "d SIG - Medium mit der Signatur 'SIG' loeschen" << endl;
				cout << "e SIG - Medium mit der Signatur 'SIG' ausleihen" << endl;
				cout << "r SIG - Medium mit der Signatur 'SIG' zurückgeben" << endl;
				cout << "h - Hilfe anzeigen" << endl;
				cout << "q - Programm beenden" << endl;
				break;
			}
			// exit program
			case 'q': {
				// first delete the objects in the library
				lib->deleteAll();
				// then delete the library
				delete lib;
				cout << "[INFO]  Programm wurde beendet!" << endl;
				break;
			}
			// default switch
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
