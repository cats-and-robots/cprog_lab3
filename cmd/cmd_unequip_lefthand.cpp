/*
 * cmd_unequip_lefthand.cpp
 *
 *  Created on: 3 mar 2014
 *      Author: findus
 */

#include "cmd_unequip_lefthand.hpp"

unequip_lefthand::unequip_lefthand(){}

unequip_lefthand::~unequip_lefthand(){}

std::pair< p_P, p_R > unequip_lefthand::execute(p_P P, p_R R, std::string com = ""){
	if (! P->isEquipped_LH()){
		std::cout<<"You have nothing equipped to your left hand!"<<std::endl;
		return std::make_pair( std::move(P), std::move(R) );
	}
	p_O old_weapon = P->unequip_LH();
	std::cout<<"Put "<<old_weapon->name()<<" back into the inventory."<<std::endl;
	P->inventory->put(std::move(old_weapon));
	return std::make_pair( std::move(P), std::move(R) );

}
