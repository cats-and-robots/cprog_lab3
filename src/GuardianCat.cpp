/*
 * GuardianCat.cpp
 *
 *  Created on: 5 mar 2014
 *      Author: findus
 */

#include "GuardianCat.hpp"

GuardianCat::GuardianCat(std::string name, std::string use_code):
Cat::Cat(name) , use_code_(use_code), entrance_(false)
{
	std::unique_ptr<Inventory> inv(new Inventory);
	this->inventory = std::move(inv);
}

GuardianCat::~GuardianCat(){}

std::string GuardianCat::type() const{
	return "GuardianCat";
}
std::unique_ptr<Inventory> GuardianCat::talk(){
	if (entrance_){
		std::cout<<"\nI am guarding this entrance!\n"
				<<"Inside this mansion lies a cat café hidden somewhere.\n"
				<<"To find it, you have to fight against evil cats and robots.\n"
				<<"The evil cats will attack you with their claws, and the evil robots\n"
				<<"will ask you tricky academic questions that you have to solve!\n"
				<<"Item, weapons and potions are scattered all over the mansion.\n"
				<<"That is all I can tell you.\n"
				<<"Good luck on your quest!\n"<<std::endl;
		if (this->inventory) return std::move(this->inventory);
		else return nullptr;
	}
	else{
		std::cout<<"\nですですですですか...\n"<<std::endl;
	}
	return nullptr;
}
bool GuardianCat::use(std::string item_code){

	if (this->use_code_ == item_code){
		entrance_ = true;
		return true;
	}
	else
		return false;
}
