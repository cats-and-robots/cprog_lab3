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
	main_hall->link_exit(entrance);
	main_hall->link(cat_cafe);
	main_hall->link(second_floor);
	cat_cafe->link_exit(main_hall);
	second_floor->link(bathroom);
	second_floor->link_exit(main_hall);
	bathroom->link_exit(second_floor);

	//set starting room
	current_room_ = entrance;
	std::cout<<"Entrance: "<<entrance->name()<<std::endl;
//	current_room_ = main_hall;


	//create items and weapons
	p_O small_knife(new Weapon("Small Knife", "A small kitchen knife", 2,0));
	p_O heavy_axe(new Weapon("Heavy Axe", "A big powerful axe", 10,3));
	p_O google_glass(new Item("Google Glass", "Device to help you translate japanese to english"));
	p_O small_potion(new Potion("Small Potion", "Restores a small amount of your health", 10));
	p_O big_potion(new Potion("Big Potion", "Restores a lot of your health!", 110));
	p_O small_poison(new Potion("Small Poison", "Damage your health a little", -20));
	p_O big_poison(new Potion("Big Poison", "Damage your health a lot!", -120));

	//Create player and actors
	p_P tmp(new Player("Hero"));
	Hero_ = std::move(tmp);
	p_F cat_1(new Cat("Siamese"));
	p_F cat_2(new Cat("Scottish Fold"));
	p_F cat_3(new Cat("Munchkin"));

	//insert items/weapons on actors and rooms
	Hero_->inventory->put(std::move(small_knife));
	Hero_->inventory->put(std::move(heavy_axe));
	Hero_->inventory->put(std::move(small_potion));
	Hero_->inventory->put(std::move(big_potion));
	Hero_->inventory->put(std::move(small_poison));
	Hero_->inventory->put(std::move(big_poison));
	current_room_->put(std::move(google_glass));
	current_room_->enter(std::move(cat_1));
	current_room_->enter(std::move(cat_2));
	current_room_->enter(std::move(cat_3));

	//save all the room pointers in a vector
	all_rooms_.push_back(std::move(entrance));
	all_rooms_.push_back(std::move(main_hall));
	all_rooms_.push_back(std::move(cat_cafe));
	all_rooms_.push_back(std::move(second_floor));
	all_rooms_.push_back(std::move(bathroom));

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

	p_cmd cmd_equip_lefthand(new equip_lefthand);
	cmds_.insert (std::pair< std::string, p_cmd >
		("equip lefthand",std::move(cmd_equip_lefthand)) );

	p_cmd cmd_unequip_righthand(new unequip_righthand);
	cmds_.insert (std::pair< std::string, p_cmd >
		("unequip righthand",std::move(cmd_unequip_righthand)) );

	p_cmd cmd_unequip_lefthand(new unequip_lefthand);
	cmds_.insert (std::pair< std::string, p_cmd >
		("unequip lefthand",std::move(cmd_unequip_lefthand)) );

	p_cmd cmd_look_around(new look_around);
	cmds_.insert (std::pair< std::string, p_cmd >
		("look around",std::move(cmd_look_around)) );

	p_cmd cmd_directions(new directions);
	cmds_.insert (std::pair< std::string, p_cmd >
		("directions",std::move(cmd_directions)) );

	p_cmd cmd_take(new take);
	cmds_.insert (std::pair< std::string, p_cmd >
		("take",std::move(cmd_take)) );

	p_cmd cmd_talk_to(new talk_to);
	cmds_.insert (std::pair< std::string, p_cmd >
		("talk to",std::move(cmd_talk_to)) );

	p_cmd cmd_go_to(new go_to);
	cmds_.insert (std::pair< std::string, p_cmd >
		("go to",std::move(cmd_go_to)) );

	p_cmd command_exit(new exit_room);
	cmds_.insert (std::pair< std::string, p_cmd >
		("exit",std::move(command_exit)) );

	p_cmd command_use(new use_object);
	cmds_.insert (std::pair< std::string, p_cmd >
		("use",std::move(command_use)) );

	p_cmd command_info(new object_info);
	cmds_.insert (std::pair< std::string, p_cmd >
		("info",std::move(command_info)) );

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

void TheGame::lex_analys(const std::string& input, std::string& command, std::string& object) const{
/* Tries to separate the command and object
 * from the input string given by the user.
 * If there is no found command,
 * then command will be the same as input
 * and object will be unchanged
 */

	std::stringstream ss(input);
	char delim = ' '; //split-character
	std::string elem;
	bool command_found = false;
	//split the input on each occurrence of space
    while (std::getline(ss, elem, delim)) {
    	if ( ! command_found){
    		if(command.empty()) command += elem;
    		else command += " "+ elem;
    		if(cmd_exist(command))
    			command_found = true;
    		continue;
    	}
    	if (object.empty()) object += elem;
    	else object += " "+ elem;
    }

}

void TheGame::take_command(){
	std::string command;
	std::string object;
	std::string input = read_string();
	if (input == "kill") {
		continue_game_=false;
		return;
	}
	lex_analys(input, command, object);

	//method that checks if the command exist
	if (!cmd_exist(command))
		std::cout<<"Command <"<<command<<"> does not exist!"<<std::endl;
	else
		std::tie(Hero_,current_room_) = cmds_[command]->
		execute(std::move(Hero_), std::move(current_room_), object);

}

void TheGame::battle(){
	std::cout<<"Called method battle..."<<std::endl;
	std::vector<p_F> enemies = current_room_->leave_all();
	if (enemies.size()>0){
		for (auto iter = enemies.begin(); iter != enemies.end(); ++iter){
			std::cout<<(*iter)->name()<<std::endl;
		}
		current_room_->enter_all(enemies);
	}
	else
		std::cout<<"No enemies to battle."<<std::endl;


}

//////////////////////////////////////////////////////////////////////
void TheGame::playTheGame(){
	std::cout<<"PUT IN GAME LOGIC HERE!!!"<<std::endl;
//	current_room_->description();
//	current_room_->directions();
//	Hero_->stats();

	continue_game_ = true;
	while (continue_game_){
		this->take_command();
		battle();
	}
	std::cout<<"Good bye!"<<std::endl;
}
