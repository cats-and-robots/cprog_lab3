/*
 * cmd_talk_to.cpp
 *
 *  Created on: 3 mar 2014
 *      Author: findus
 */

#include "cmd_talk_to.hpp"

talk_to::talk_to(){}

talk_to::~talk_to(){}

std::pair< p_P, p_R > talk_to::execute(p_P P, p_R R, std::string com){
	p_F actor = R->leave(com);
	if (actor){
		p_Inv invent = actor->talk();
		if (invent){
			std::vector<p_O> items = invent->loot();
			if (items.size()>0){
				std::cout<<"Received the following stuff from <"<<actor->type()<<"> "<<actor->name()<<":"<<std::endl;
				for (unsigned int i = 0; i<items.size(); ++i){
					std::cout<<"   <"<<items[i]->type()<<"> "<<items[i]->name()<<std::endl;
				}
				P->inventory->put_all( items );
			}
		}
		//if we talk to an Evil actor, change the players battle mode to true
		if (actor->type() == "EvilCat" || actor->type() == "EvilRobot")
			P->do_battle = true;
		R->enter(std::move(actor));

	}
	else
		std::cout<<"There is no character in the area with the name <"<<com<<">"<<std::endl;
	return std::make_pair( std::move(P), std::move(R) );

}
