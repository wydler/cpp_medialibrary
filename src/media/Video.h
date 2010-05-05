/*
 * Video.h
 *
 *  Created on: 05.04.2010
 *      Author: Michael Wydler
 */

#ifndef VIDEO_H_
#define VIDEO_H_

#include <string>
#include "Medium.h"

class Video : public Medium{
public:
	Video();
	virtual ~Video();
	double getLenght() { return lenght; };
	void setLenght( double _lenght ) { lenght = _lenght; };
	virtual void print();
private:
	double inputLenght();
	double lenght;
};

#endif /* VIDEO_H_ */
