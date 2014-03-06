/*
 * CafeRobot.cpp
 *
 *  Created on: 11 feb 2014
 *      Author: findus
 */

#include "CafeRobot.hpp"

CafeRobot::CafeRobot(std::string name)
{
	name_ = name;
	current_HP_ = 1;
	max_HP_ = 1;
	DEF_ = 0;
	ATK_ = 0;
}

CafeRobot::~CafeRobot(){}

std::string CafeRobot::type() const{
	return "CafeRobot";
}

int CafeRobot::attack(){
	return ATK_;
}

std::unique_ptr<Inventory> CafeRobot::talk(){
	std::cout<<"\n*BLIP-BLOP* Todays special is soup with cat-hair *BUZZ*\n"<<
			"When you feel you are at peace, say the magic words: \"I am home\".\n"<<std::endl;
	if (this->inventory) return std::move(this->inventory);
	else return nullptr;
}

