/*
 * Medium.h
 *
 *  Created on: 05.04.2010
 *      Author: Michael Wydler
 */

#ifndef MEDIUM_H_
#define MEDIUM_H_

#include <string>
#include <iostream>

class Medium {
public:
	Medium();
	Medium(int) {};
	virtual ~Medium();
	unsigned int getSignature() { return signature; };
	std::string getTitle() { return title; };
	std::string getType() { return type; };
	bool getState() { return state; };
	void setSignature( unsigned int _sig ) { signature = _sig; };
	void setTitle( std::string _title) { title = _title; };
	void setType( std::string _type) { type = _type; };
	void setState( bool _state) { state = _state; };
	std::string printState();
	virtual std::string getDetails() { return " "; };
	friend std::ostream &operator<<(std::ostream &ostr, Medium* item);
protected:
	std::string inputTitle();
	int inputSignature();
	unsigned int signature;
	std::string title;
	std::string type;
	bool state;
};

#endif /* MEDIUM_H_ */
