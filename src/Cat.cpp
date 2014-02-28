/*
 * Cat.cpp
 *
 *  Created on: 11 feb 2014
 *      Author: findus
 */
#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat(std::string name)
{
	name_ = name;
	current_HP_ = 1;
	max_HP_ = 1;
	DEF_ = 0;
	ATK_ = 0;
}

Cat::Cat(std::string name, int hp, int def, int atk)
{
	name_ = name;
	current_HP_ = hp;
	max_HP_ = hp;
	DEF_ = def;
	ATK_ = atk;
}


Cat::~Cat() {std::cout<<"Destroyed "<<type()<<" "<<name()<<std::endl;}

std::string Cat::type() const{
	return "Cat";
}

void Cat::talk(){
	std::cout<<"\nNnyyyaa nnnyyaaa! =^w^= \n\n";
}

