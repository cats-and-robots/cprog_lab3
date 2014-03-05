/*
 * cmd_take.cpp
 *
 *  Created on: 3 mar 2014
 *      Author: findus
 */

#include "cmd_take.hpp"

take::take() {}

take::~take(){}

std::pair< p_P, p_R > take::execute(p_P P, p_R R, std::string com){
	p_O item = R->take(com);
	if (item){
		std::cout<<"Put "<<item->name()<<" to inventory."<<std::endl;
		P->inventory->put(std::move(item));
	}
	else
		std::cout<<"Object <"<<com<<"> does not exist!"<<std::endl;
	return std::make_pair( std::move(P), std::move(R) );
}
