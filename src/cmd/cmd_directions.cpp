/*
 * cmd_directions.cpp
 *
 *  Created on: 3 mar 2014
 *      Author: findus
 */

#include "cmd_directions.hpp"

directions::directions(){}

directions::~directions(){}

std::pair< p_P, p_R > directions::execute(p_P P, p_R R, std::string com = ""){
	R->directions();
	return std::make_pair( std::move(P), std::move(R) );
}
