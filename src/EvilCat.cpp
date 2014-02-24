/*
 * EvilCat.cpp
 *
 *  Created on: 11 feb 2014
 *      Author: findus
 */

#include "EvilCat.hpp"

EvilCat::EvilCat(std::string name):
Cat::Cat(name, 25, 1, 2){}

EvilCat::EvilCat(std::string name,int hp , int def , int atk):
Cat::Cat(name, hp, def, atk){}

EvilCat::~EvilCat() {std::cout<<"Destroyed "<<type()<<" "<<name()<<std::endl;}

std::string EvilCat::type() const{
	return "EvilCat";
}
void EvilCat::talk() const{
	std::cout<<"\nkekekekek! *_*"<<"\n\n";
}
