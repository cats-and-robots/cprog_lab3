/*
 * cmd_equip_righthand.cpp
 *
 *  Created on: 3 mar 2014
 *      Author: findus
 */

#include "cmd_equip_righthand.hpp"

equip_righthand::equip_righthand(){}

equip_righthand::~equip_righthand(){}

std::pair< p_P, p_R > equip_righthand::execute(p_P P, p_R R, std::string com = ""){
	if (P->isEquipped_RH()){
		std::cout<<"You have already equipped your right hand!"<<std::endl;
		return std::make_pair( std::move(P), std::move(R) );
	}
	std::vector<std::string> weapon_list;
	weapon_list = P->inventory->get_weapons_name();
	int nr_of_weapons = weapon_list.size();
	if (nr_of_weapons>0){

		int answer = 1; //set default to take the first weapon if there is only one weapon in the inventory
		if (nr_of_weapons > 1){
			std::cout<<"Weapons in your inventory to choose from:"<<std::endl;
			for (int i = 0; i< nr_of_weapons; ++i){
				std::cout<<i+1<<": "<<weapon_list[i]<<std::endl;
			}
			while (true){
				std::cout << "Please enter a number between 1 and "<<nr_of_weapons<<std::endl;
				answer = this->read_int();
				if (answer >0 && answer <= nr_of_weapons)
					break;
				std::cout<<"Not a number between 1 and "<<nr_of_weapons<<std::endl;
			}
		}
		//equip new weapon
		p_O new_weapon = P->inventory->take(weapon_list[answer-1]);
		std::cout<<"Equipped "<<new_weapon->name()<<" to "<<P->name()<<"'s right hand."<<std::endl;
		P->equip_RH(std::move(new_weapon));
	}
	else
		std::cout<<"You have no weapons in your inventory!"<<std::endl;

	return std::make_pair( std::move(P), std::move(R) );
}

