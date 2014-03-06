/*
 * Animal.hpp
 *
 *  Created on: 11 feb 2014
 *      Author: findus
 */

#ifndef ANIMAL_HPP_
#define ANIMAL_HPP_

#include "Character.hpp"
#include <iostream>
#include <string>

class Animal: public Character{

public:
	virtual ~Animal(){};

	virtual std::string type() const = 0;
	virtual std::string baseType() const{return "Animal";}
	virtual int attack() {return ATK_;}
	virtual std::unique_ptr<Inventory> talk() = 0;
	virtual void stats() const{std::cout<<"Name: " << name() << "\nType: "<< type()<<std::endl;}

};


#endif /* ANIMAL_HPP_ */
