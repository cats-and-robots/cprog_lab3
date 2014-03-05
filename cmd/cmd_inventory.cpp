/*
 * cmd_inventory.cpp
 *
 *  Created on: 3 mar 2014
 *      Author: findus
 */

#include "cmd_inventory.hpp"

inventory::inventory(){}

inventory::~inventory(){}

std::pair< p_P, p_R > inventory::execute(p_P P, p_R R, std::string com = ""){
	P->inventory->show_inventory();
	return std::make_pair( std::move(P), std::move(R) );
}

