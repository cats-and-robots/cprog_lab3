/*
 * cmd_use.cpp
 *
 *  Created on: 3 mar 2014
 *      Author: findus
 */

#include "cmd_use.hpp"

use_object::use_object(){}

use_object::~use_object(){}

std::pair< p_P, p_R > use_object::execute(p_P P, p_R R, std::string com){
	p_O item = P->inventory->take(com);
	if (item){
		if (item->type()=="Item"){
			if ( R->use_item(item->use_code()) )
				std::cout<<P->name()<<" used <"<<item->type()<<"> "<<item->name()<<"!"<<std::endl;
			else{
				std::cout<<"You cannot use <"<<item->type()<<"> "<<item->name()<<" here!"<<std::endl;
				P->inventory->put(std::move(item));
			}
		}
		else if (item->type()=="Weapon"){
			std::cout<<"You cannot use <"<<item->type()<<"> "<<item->name()<<"!\n"<<
					"You can only equip yourself with it!"<<std::endl;
			P->inventory->put(std::move(item));
		}
		else if (item->type() == "Potion"){
			int effect = item->use_value();
			std::cout<<P->name()<<" used <"<<item->type()<<"> "<<item->name()<<"!"<<std::endl;
			if (effect>=0) std::cout<<P->name()<<" restored "<<effect<<" health points!"<<std::endl;
			else std::cout<<P->name()<<" lost "<< abs(effect)<<" health points!"<<std::endl;
			//negativ damage == gain health
			P->takeDamage( - effect);
		}
		else{
			std::cout<<"Unknown object!"<<std::endl;
			P->inventory->put(std::move(item));
		}
	}
	else
		std::cout<<"There is no object in inventory called <"<<com<<">"<<std::endl;
	return std::make_pair( std::move(P), std::move(R) );

}
