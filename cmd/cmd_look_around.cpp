/*
 * cmd_look_around.cpp
 *
 *  Created on: 3 mar 2014
 *      Author: findus
 */

#include "cmd_look_around.hpp"

look_around::look_around(){}

look_around::~look_around(){}

std::pair< p_P, p_R > look_around::execute(p_P P, p_R R, std::string com = ""){
	R->description();
	return std::make_pair( std::move(P), std::move(R) );
}
