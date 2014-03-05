/*
 * Robot.hpp
 *
 *  Created on: 11 feb 2014
 *      Author: findus
 */

#ifndef ROBOT_HPP_
#define ROBOT_HPP_

#include <iostream>
#include "Fighter.hpp"


class Robot: public Fighter{

public:
	virtual ~Robot(){};

	virtual std::string type() const = 0;
	virtual int attack() = 0;
	virtual std::unique_ptr<Inventory> talk() = 0;

	std::string baseType() const{return "Robot";}
	virtual void stats() const{std::cout<<"Name: " << name() << "\nType: "<< type()<<std::endl;}

};

#endif /* ROBOT_HPP_ */
