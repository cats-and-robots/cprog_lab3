/*
 * Potion.cpp
 *
 *  Created on: 3 mar 2014
 *      Author: findus
 */

#include "Potion.hpp"

//Potion::Potion():
//Item::Item(){}

Potion::Potion(std::string name, std::string info, int health):
Item::Item(name,info)
{
	use_value_= health;
}

Potion::~Potion(){}

int Potion::getATK() const{
	return 0;
}
int Potion::getDEF() const{
	return 0;
}

std::string Potion::type() const{
	return "Potion";
}
