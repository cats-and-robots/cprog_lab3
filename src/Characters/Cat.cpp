/*
 * Cat.cpp
 *
 *  Created on: 11 feb 2014
 *      Author: findus
 */

#include "Cat.hpp"

Cat::Cat(std::string name)
{
	name_ = name;
	current_HP_ = 1;
	max_HP_ = 1;
	DEF_ = 0;
	ATK_ = 0;
}

Cat::Cat(std::string name, int hp, int atk, int def)
{
	name_ = name;
	current_HP_ = hp;
	max_HP_ = hp;
	ATK_ = atk;
	DEF_ = def;
}


Cat::~Cat(){}

std::string Cat::type() const{
	return "Cat";
}

std::unique_ptr<Inventory> Cat::talk(){
	std::cout<<"\nNnyyyaa nnnyyaaa! =^w^= \n\n";
	if (this->inventory) return std::move(this->inventory);
	else return nullptr;
}

