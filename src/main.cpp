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
#include <limits>

#include "media/Medium.h"
#include "media/Book.h"
#include "media/Video.h"
#include "array_library/Library.h"
#include "dynamic_library/Container.h"

using namespace std;

int main() {
	// create variable for action
	char action;

	// create static library
	//Library* lib = new Library();

	// create dynamic library
	Container* lib = new Container();

	while( action != 'q' ) {
		// input new action
		cin.clear();
		cout << endl;
		cout << "Bitte Aktion eingeben: ";
		cin >> action;

		// switch to desired action
		switch( action ) {
			// create medium
			case 'm': {
				bool flag = lib->add(new Medium());
				if(flag == false) {
					cerr << "  [ERROR] Medium konnte nicht erstellt werden!" << endl;
				}
				break;
			}
			// create book
			case 'b': {
				bool flag = lib->add(new Book());
				if(flag == false) {
					cerr << "  [ERROR] Buch konnte nicht erstellt werden!" << endl;
				}
				break;
			}
			// create video
			case 'v': {
				bool flag = lib->add(new Video());
				if(flag == false) {
					cerr << "  [ERROR] Video konnte nicht erstellt werden!" << endl;
				}
				break;
			}
			// print library-list
			case 'l': {
				ITEM* item = NULL;
				lib->begin();
				while((item = lib->getItem()) != NULL) {
					cout << item;
					lib->next();
				}
				break;
			}
			// remove medium
			case 'd': {
				unsigned int sig;
				cin >> sig;

				ITEM* item = NULL;
				lib->begin();
				while((item = lib->getItem()) != NULL) {
					if(item->getSignature() == sig) {
						bool flag = lib->remove();
						if(flag == true) {
							cout << "  [INFO] Datensatz gelöscht" << endl;
						} else {
							cerr << "  [ERROR] Fehler beim löschen des Datensatz!" << endl;
						}
					} else {
						cerr << "  [ERROR] Signatur nicht gefunden!" << endl;
					}
					lib->next();
				}
				break;
			}
			// borrow a medium
			case 'e': {
				int flag = 0;
				unsigned int tmpSig = 0;

				cin >> tmpSig;

				ITEM* item = NULL;
				lib->begin();
				while((item = lib->getItem()) != NULL) {
					if( item->getSignature() == tmpSig ) {
						if( item->getState() == false ) {
							item->setState(true);
							std::cout << "  " << item->getType() << " " << item->getSignature() << " wurde als entliehen markiert." << std::endl;
						} else {
							std::cerr << "  " << item->getType() << " " << item->getSignature() << " ist schon als entliehen markiert." << std::endl;
						}
						flag++;
					}
					lib->next();
				}

				if( flag == 0 ) {
					std::cerr << "  [ERROR] Signatur " << tmpSig << " existiert nicht!" << std::endl;
				}
				break;
			}
			// return a medium
			case 'r': {
				int flag = 0;
				unsigned int tmpSig = 0;

				cin >> tmpSig;

				ITEM* item = NULL;
				lib->begin();
				while((item = lib->getItem()) != NULL) {
					if( item->getSignature() == tmpSig ) {
						if( item->getState() == true ) {
							item->setState(false);
							std::cout << "  " << item->getType() << " " << item->getSignature() << " wurde als vorhanden markiert." << std::endl;
						} else {
							std::cerr << "  " << item->getType() << " " << item->getSignature() << " ist schon als vorhanden markiert." << std::endl;
						}
						flag++;
					}
					lib->next();
				}

				if( flag == 0 ) {
					std::cerr << "  [ERROR] Signatur " << tmpSig << " existiert nicht!" << std::endl;
				}
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
				//lib->deleteAll();
				// then delete the library
				delete lib;
				cout << " [INFO] Programm wurde beendet!" << endl;
				break;
			}
			// default switch
			default: {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cerr << " [ERROR] Keine gültige Aktion eingeben!" << endl;
				break;
			}
		}
	}

	return 0;
}
