/*
 * Weapon.cpp
 *
 *  Created on: 13 feb 2014
 *      Author: findus
 */

#include "Weapon.hpp"

Weapon::Weapon(std::string name,std::string info,int atk,int def):
Item::Item(name,info)
{
	ATK_ = atk;
	DEF_ = def;
}

Weapon::~Weapon(){}

std::string Weapon::type() const{
	return "Weapon";
}

int Weapon::getATK() const{
	return ATK_;
}

int Weapon::getDEF() const{
	return DEF_;
}
