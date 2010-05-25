/*
 * Notifier.h
 *
 *  Created on: 25.05.2010
 *      Author: michael
 */

#ifndef NOTIFIER_H_
#define NOTIFIER_H_

#include <iostream>
#include <string>

class Notifier {
public:
	Notifier();
	virtual ~Notifier();
	void info(std::string head);
	void info(std::string head, std::string body);
	void success(std::string head);
	void success(std::string head, std::string body);
	void error(std::string head);
	void error(std::string head, std::string body);
};

#endif /* NOTIFIER_H_ */
