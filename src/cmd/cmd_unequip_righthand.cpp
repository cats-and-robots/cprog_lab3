/*
 * cmd_unequip_righthand.cpp
 *
 *  Created on: 3 mar 2014
 *      Author: findus
 */

#include "cmd_unequip_righthand.hpp"

unequip_righthand::unequip_righthand(){}

unequip_righthand::~unequip_righthand(){}

std::pair< p_P, p_R > unequip_righthand::execute(p_P P, p_R R, std::string com = ""){
	if (! P->isEquipped_RH()){
		std::cout<<"You have nothing equipped to your right hand!"<<std::endl;
		return std::make_pair( std::move(P), std::move(R) );
	}
	p_O old_weapon = P->unequip_RH();
	std::cout<<"Put <"<< old_weapon->type() <<"> "<<old_weapon->name()<<" back into inventory."<<std::endl;
	P->inventory->put(std::move(old_weapon));
	return std::make_pair( std::move(P), std::move(R) );

}
