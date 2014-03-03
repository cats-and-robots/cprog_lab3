/*
 * Weapon.cpp
 *
 *  Created on: 13 feb 2014
 *      Author: findus
 */

#include "Weapon.hpp"

Weapon::Weapon()
//Item::Item()
{
	name_="";
	info_="";
	use_= 0;
	ATK_ = 0;
	DEF_ = 0;
}

Weapon::Weapon(std::string name,std::string info,int atk,int def)
//Item::Item(name,info)
{
	name_=name;
	info_=info;
	use_= 0;
	ATK_ = atk;
	DEF_ = def;
}

Weapon::~Weapon() {std::cout<<"Destroyed "<<type()<<" "<<name()<<std::endl;}

std::string Weapon::type() const{
	return "Weapon";
}

int Weapon::getATK() const{
	return ATK_;
}

int Weapon::getDEF() const{
	return DEF_;
}
