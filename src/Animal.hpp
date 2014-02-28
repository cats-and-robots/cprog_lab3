/*
 * Animal.hpp
 *
 *  Created on: 11 feb 2014
 *      Author: findus
 */

#ifndef ANIMAL_HPP_
#define ANIMAL_HPP_

#include "Fighter.hpp"
#include <iostream>
#include <string>

class Animal: public Fighter{

public:
	virtual ~Animal(){};

	virtual std::string type() const = 0;
	virtual std::string baseType() const{return "Animal";}
	virtual int attack() {return ATK_;}
	virtual void talk() const= 0;


	friend std::ostream& operator<<(std::ostream& stream, const Animal& x){
		stream <<"Name: " << x.name() << "\nType: "<< x.type() <<"\nHP: "
				<< x.current_HP() <<"/"<<x.max_HP_;
		return stream;
	}
};


#endif /* ANIMAL_HPP_ */
