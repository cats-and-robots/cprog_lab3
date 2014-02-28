/*
 * CafeRobot.hpp
 *
 *  Created on: 11 feb 2014
 *      Author: findus
 */

#ifndef CAFEROBOT_HPP_
#define CAFEROBOT_HPP_

#include "Robot.hpp"

class CafeRobot: public Robot {
public:
	CafeRobot(std::string);
	virtual ~CafeRobot();

	virtual std::string type() const;
	virtual int attack();
	virtual void talk();

	friend std::ostream& operator<<(std::ostream&, const Robot&);
};

#endif /* CAFEROBOT_HPP_ */
