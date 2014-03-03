/*
 * TheGame.cpp
 *
 *  Created on: 1 mar 2014
 *      Author: findus
 */

#include "TheGame.hpp"

TheGame::TheGame(){
	std::cout<<"Created a TheGame object!"<<std::endl;

	//load commands into map cmds_
	load_cmds();

	//Create rooms
	p_R entrance(new Room("Entrance"));
	p_R main_hall(new Room("Main hall"));
	p_R cat_cafe(new Room("Cat Café"));
	p_R second_floor(new Room("Second floor"));
	p_R bathroom(new Room("Bathroom"));

	//Link the rooms
	entrance->link(main_hall);
	main_hall->link(cat_cafe);
	main_hall->link(second_floor);
	main_hall->link_exit(entrance);
	cat_cafe->link_exit(main_hall);
	second_floor->link(bathroom);
	second_floor->link_exit(main_hall);
	bathroom->link_exit(second_floor);

	//set starting room
	currentRoom_ = entrance;

	//create items and weapons
	p_O small_knife(new Weapon("Small knife", "A small kitchen knife", 2,0));
	p_O heavy_axe(new Weapon("Heavy Axe", "A big powerful axe", 10,3));
	p_O google_glass(new Item("Google Glass", "Device to help you translate japanese to english"));

	//Create player and actors
	p_P tmp(new Player("Hero"));
	Hero_ = std::move(tmp);

	//insert items/weapons on actors and rooms
	Hero_->inventory->put(std::move(small_knife));
	Hero_->inventory->put(std::move(heavy_axe));
	Hero_->inventory->put(std::move(google_glass));


}

TheGame::~TheGame() {
	std::cout<<"Destroyed a TheGame object!"<<std::endl;
}

void TheGame::load_cmds(){
	p_cmd cmd_help(new help);
	cmds_.insert (std::pair< std::string, p_cmd >
		("help",std::move(cmd_help)) );

	p_cmd cmd_inventory(new inventory);
	cmds_.insert (std::pair< std::string, p_cmd >
		("inventory",std::move(cmd_inventory)) );

	p_cmd cmd_stats(new stats);
	cmds_.insert (std::pair< std::string, p_cmd >
		("stats",std::move(cmd_stats)) );

	p_cmd cmd_equip_righthand(new equip_righthand);
	cmds_.insert (std::pair< std::string, p_cmd >
		("equip righthand",std::move(cmd_equip_righthand)) );
}

bool TheGame::cmd_exist(std::string input_cmd) const{
	if ( cmds_.find(input_cmd) == cmds_.end() )
		return false;
	else
		return true;
}

std::string TheGame::read_string() const{
	std::string input = "";
	std::cout<<">> ";
	std::getline(std::cin, input);
	return input;
}

//int TheGame::read_int() const{
//	std::string input = "";
//	int int_input = 0;
//	while (true){
//		std::cout<<">> ";
//		std::getline(std::cin, input);
//
//		std::stringstream myStream(input);
//		if (myStream >> int_input)
//			break;
//		std::cout << "Not an integer, please try again!" << std::endl;
//	}
//	return int_input;
//}

void TheGame::take_command(){
	/* if there are no spaces, it's a command
	 * else, everything after the last space is some kind of object to
	 * the command.
	 * Exceptions: <equip righthand/lefthand>, <unequip righthand/lefthand>,
	 * <look around>
	 */

	std::string input = read_string();
	std::string command;
	std::string object;
	std::size_t pos_found = input.find_last_of(" ");

	if (pos_found!=std::string::npos){
		command = input.substr(0,pos_found);
		if (command == "equip" || command == "unequip" ||command == "look")
			command = input; //the command does not carry any object
		else
			object = input.substr(pos_found+1);
	}
	else
		command = input;

	std::cout<<"command: <"<<command<<">"<<std::endl;
	std::cout<<"object: <"<<object<<">"<<std::endl;

	//method that checks if the command exist
	if (!cmd_exist(command))
		std::cout<<"Command <"<<command<<"> does not exist!"<<std::endl;
	else
		std::tie(Hero_,currentRoom_) = cmds_[command]->
		execute(std::move(Hero_), std::move(currentRoom_), object);

}


//////////////////////////////////////////////////////////////////////
void TheGame::playTheGame(){
	std::cout<<"PUT IN GAME LOGIC HERE!!!"<<std::endl;
	currentRoom_->description();
	currentRoom_->directions();
	Hero_->stats();


	while (true){
		this->take_command();
	}
}
