/*
 * cmd_object_info.cpp
 *
 *  Created on: 3 mar 2014
 *      Author: findus
 */

#include "cmd_object_info.hpp"

object_info::object_info(){}

object_info::~object_info(){}

std::pair< p_P, p_R > object_info::execute(p_P P, p_R R, std::string com){
	p_O item = P->inventory->take(com);
	if (item){
		std::cout<<item->info()<<std::endl;
		P->inventory->put(std::move(item));
	}
	else
		std::cout<<"There is no object in inventory called <"<<com<<">"<<std::endl;
	return std::make_pair( std::move(P), std::move(R) );

}
