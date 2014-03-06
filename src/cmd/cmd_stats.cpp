/*
 * cmd_stats.cpp
 *
 *  Created on: 3 mar 2014
 *      Author: findus
 */

#include "cmd_stats.hpp"

stats::stats(){}

stats::~stats(){}

std::pair< p_P, p_R > stats::execute(p_P P, p_R R, std::string com = ""){
	P->stats();
	return std::make_pair( std::move(P), std::move(R) );
}

