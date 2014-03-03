/*
 * help.cpp
 *
 *  Created on: 2 mar 2014
 *      Author: findus
 */

#include "help.hpp"

help::help(){}

help::~help() {}

std::pair< p_P, p_R > help::execute(p_P P, p_R R, std::string com = ""){
	int align = 25;
	std::cout<<"These are the commands you can write:"<<std::endl;
	std::cout<<std::left << std::setfill('.') <<std::setw(align) <<
			"   inventory"<<"see all your stuff."<<std::endl;
	std::cout<<std::left << std::setfill('.') <<std::setw(align) <<
			"   stats"<<"see your current stats."<<std::endl;
	std::cout<<std::left << std::setfill('.') <<std::setw(align) <<
			"   equip righthand"<<"set weapon to your right hand."<<std::endl;
	std::cout<<std::left << std::setfill('.') <<std::setw(align) <<
			"   equip lefthand"<<"set weapon to your left hand."<<std::endl;
	std::cout<<std::left << std::setfill('.') <<std::setw(align) <<
			"   unequip righthand"<<"remove weapon from your right hand."<<std::endl;
	std::cout<<std::left << std::setfill('.') <<std::setw(align) <<
			"   unequip lefthand"<<"remove weapon from your left hand."<<std::endl;
	std::cout<<std::left << std::setfill('.') <<std::setw(align) <<
			"   look around"<<"get information of all the things in the current area."<<std::endl;
	std::cout<<std::left << std::setfill('.') <<std::setw(align) <<
			"   take <object>"<<"put object to your inventory, ex \"take Book\"."<<std::endl;
	std::cout<<std::left << std::setfill('.') <<std::setw(align) <<
			"   talk to <character>"<<"talk to someone in the area, ex \"talk to Alex\"."<<std::endl;
	std::cout<<std::left << std::setfill('.') <<std::setw(align) <<
			"   go to <room>"<<"switch area, ex \"go to Main hall\"."<<std::endl;
	std::cout<<std::left << std::setfill('.') <<std::setw(align) <<
			"   use <object>"<<"use the object, ex \"use Potion\"."<<std::endl;
	return std::make_pair( std::move(P), std::move(R) );
}
