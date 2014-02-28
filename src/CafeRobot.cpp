/*
 * CafeRobot.cpp
 *
 *  Created on: 11 feb 2014
 *      Author: findus
 */

#include "CafeRobot.hpp"

CafeRobot::CafeRobot(std::string name){
	name_ = name;
	current_HP_ = 1;
	max_HP_ = 1;
	DEF_ = 0;
	ATK_ = 0;
}

CafeRobot::~CafeRobot() {std::cout<<"Destroyed "<<type()<<" "<<this->name()<<std::endl;}

std::string CafeRobot::type() const{
	return "CafeRobot";
}

int CafeRobot::attack(){
	return ATK_;
}

void CafeRobot::talk(){
	std::cout<<"\n*BLIP-BLOP* Todays special is soup with cat-hair *BUZZ*"<<"\n\n";
}

