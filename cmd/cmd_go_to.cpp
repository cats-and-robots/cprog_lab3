/*
 * cmd_go_to.cpp
 *
 *  Created on: 3 mar 2014
 *      Author: findus
 */

#include "cmd_go_to.hpp"

go_to::go_to(){}

go_to::~go_to(){}

std::pair< p_P, p_R > go_to::execute(p_P P, p_R R, std::string com){

	if (R->name() == com){
		std::cout<<"You are already in area "<<com<<std::endl;
		return std::make_pair( std::move(P), std::move(R) );
	}
	p_R new_room = R->neighbor(com);
	if (new_room){
		if (new_room->is_entrance_allowed()){
			std::cout<<"Entered "<<new_room->name()<<std::endl;
			R = new_room;
		}
		else{
			std::cout<<"The door is looked to "<<new_room->name()<<"!"<<std::endl;
			//Do I need to put the room back?
		}
	}
	else
		std::cout<<"Area <"<<com<<"> does not exist!"<<std::endl;
	return std::make_pair( std::move(P), std::move(R) );

}
