/*
 * Item.cpp
 *
 *  Created on: 7 feb 2014
 *      Author: findus
 */

#include "Item.hpp"

Item::Item()
{
	name_="";
	info_="";
}

Item::Item(std::string name, std::string info)
{
	name_=name;
	info_=info;
}

Item::~Item(){}

int Item::getATK() const{
	return 0;
}
int Item::getDEF() const{
	return 0;
}

std::string Item::type() const{
	return "Item";
}




