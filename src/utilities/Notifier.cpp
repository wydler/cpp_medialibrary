/*
 * Notifier.cpp
 *
 *  Created on: 25.05.2010
 *      Author: michael
 */

#include "Notifier.h"

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

Notifier::Notifier() {
	// TODO Auto-generated constructor stub

}

Notifier::~Notifier() {
	// TODO Auto-generated destructor stub
}

void Notifier::info(string head) {
	stringstream string;
	string.clear();
	string << "notify-send \"" << head << "\" -i info";
	system(string.str().c_str());
}

void Notifier::info(string head, string body) {
	stringstream string;
	string.clear();
	string << "notify-send \"" << head << "\" \"" << body << "\" -i info";
	system(string.str().c_str());
}

void Notifier::success(string head) {
	stringstream string;
	string.clear();
	string << "notify-send \"" << head << "\" -i checkbox";
	system(string.str().c_str());
}

void Notifier::success(string head, string body) {
	stringstream string;
	string.clear();
	string << "notify-send \"" << head << "\" \"" << body << "\" -i checkbox";
	system(string.str().c_str());
}

void Notifier::error(string head) {
	stringstream string;
	string.clear();
	string << "notify-send \"" << head << "\" -i error";
	system(string.str().c_str());
}

void Notifier::error(string head, string body) {
	stringstream string;
	string.clear();
	string << "notify-send \"" << head << "\" \"" << body << "\" -i error";
	system(string.str().c_str());
}
