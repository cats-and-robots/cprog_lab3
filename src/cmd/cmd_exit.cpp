/*
 * cmd_exit.cpp
 *
 *  Created on: 3 mar 2014
 *      Author: findus
 */

#include "cmd_exit.hpp"

exit_room::exit_room(){}

exit_room::~exit_room(){}

std::pair< p_P, p_R > exit_room::execute(p_P P, p_R R, std::string com){
	p_R new_room = R->exit_room();
	if (new_room){
		std::cout<<"Entered "<<new_room->name()<<std::endl;
		R = new_room;
	}
	else
		std::cout<<"There is no exit from this area!"<<std::endl;
	return std::make_pair( std::move(P), std::move(R) );

}
