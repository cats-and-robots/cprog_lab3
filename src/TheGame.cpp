/*
 * TheGame.cpp
 *
 *  Created on: 1 mar 2014
 *      Author: findus
 */

#include "TheGame.hpp"

TheGame::TheGame(){
	//load commands into map cmds_
	load_cmds();

	//create items and weapons
	p_O google_glass(new Item("Google Glass", "Device to help you translate japanese to english", "google glass"));
	p_O key_to_mansion(new Item("Rusty Key", "Key that allows access to the mansion", "mansion key"));
	p_O key_to_bathroom(new Item("Small Key", "It says \"お手洗い\". O..te..ara..i..?", "bathroom key"));
	p_O key_to_cat_cafe(new Item("Cat Key", "Key that is shaped like a cat", "cat key"));
	p_O small_knife(new Weapon("Small Knife", "A small kitchen knife", 2,0));
	p_O heavy_axe(new Weapon("Heavy Axe", "A big powerful axe", 15,0));
	p_O iron_shield(new Weapon("Iron Shield", "Good shield for defending yourself against animal claws", 0,15));
	p_O small_potion(new Potion("Small Potion", "Restores a small amount of your health", 30));
	p_O expired_milk(new Potion("Expired Milk", "Says that it expired 2012...eeuuhh", -30));



	//Create rooms
	p_R entrance(new Room("Entrance"));
	p_R mansion(new Room("Mansion", false, key_to_mansion->use_code() ));
	p_R cat_cafe(new Room("Cat Café", false, key_to_cat_cafe->use_code() ));
	p_R second_floor(new Room("Second floor"));
	p_R bathroom(new Room("Bathroom", false, key_to_bathroom->use_code() ));


	//Create player and actors
	p_P tmp(new Player("Hero"));
	Hero_ = std::move(tmp);
	p_F guardian_cat(new GuardianCat("Siamese", google_glass->use_code()));
	p_F grumpy_persian(new EvilCat("Grumpy Persian"));
	p_F dark_asimo(new EvilRobot("Dark Asimo"));
	p_F devon_rex(new EvilCat("Devon Rex", 50 , 20, 3));
	p_F dark_petman(new EvilRobot("Dark PETMAN", 3));
	p_F munchkin(new Cat("Munchkin"));
	p_F scottish_fold(new Cat("Scottish Fold"));
	p_F nao(new CafeRobot("Nao"));

	//put items and characters into the rooms
	guardian_cat->inventory->put(std::move(key_to_mansion));
	entrance->enter(std::move(guardian_cat));
	entrance->put(std::move(google_glass));
	mansion->enter(std::move(grumpy_persian));
	mansion->put(std::move(small_knife));
	dark_asimo->inventory->put(std::move(key_to_bathroom));
	dark_asimo->inventory->put(std::move(expired_milk));
	second_floor->enter(std::move(dark_asimo));
	second_floor->put(std::move(small_potion));
	dark_petman->inventory->put(std::move(key_to_cat_cafe));
	bathroom->enter(std::move(devon_rex));
	bathroom->enter(std::move(dark_petman));
	bathroom->put(std::move(heavy_axe));
	bathroom->put(std::move(iron_shield));
	cat_cafe->enter(std::move(munchkin));
	cat_cafe->enter(std::move(scottish_fold));
	cat_cafe->enter(std::move(nao));

	//Link the rooms
	entrance->link(mansion);
	mansion->link_exit(entrance);

	//link mansion->cat cafe will be done in stage 2

	//link mansion->second floor will be done in stage 1
	second_floor->link(bathroom);
	second_floor->link_exit(mansion);
	bathroom->link_exit(second_floor);

	//set starting room
	current_room_ = entrance;

	//save all the room pointers in a map, or else the rooms will be destroyed when we switch room!
	all_rooms_.insert (std::pair< std::string, p_R >
		(entrance->name(),std::move(entrance)) );
	all_rooms_.insert (std::pair< std::string, p_R >
		(mansion->name(),std::move(mansion)) );
	all_rooms_.insert (std::pair< std::string, p_R >
		(cat_cafe->name(),std::move(cat_cafe)) );
	all_rooms_.insert (std::pair< std::string, p_R >
		(second_floor->name(),std::move(second_floor)) );
	all_rooms_.insert (std::pair< std::string, p_R >
		(bathroom->name(),std::move(bathroom)) );



}

TheGame::~TheGame(){}

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

int TheGame::read_int() const{
	std::string input = "";
	int int_input = 0;
	while (true){
		std::cout<<">> ";
		std::getline(std::cin, input);
		std::stringstream myStream(input);
		if (myStream >> int_input)
			break;
		std::cout << "Not an integer, please try again!" << std::endl;
	}
	return int_input;
}

void TheGame::lex_analys(const std::string& input, std::string& command, std::string& object) const{
/* Tries to separate the command and object
 * from the input string given by the user.
 * If there is no found command,
 * then command will be the same as input
 * and object will be unchanged
 */

	std::stringstream ss(input);
	char delim = ' ';
	std::string elem;
	bool command_found = false;
	//split the input on each occurrence of delim (space)
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
	//debug command to kill each stage
	if (input == "kill myself") {
		continue_game_=false;
		return;
	}
	if (input == "I am home" && current_room_->name()== "Cat Café") {
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
	std::vector<p_F> enemies = current_room_->leave_all_evil();
	if (enemies.size()==0){
		std::cout<<"No enemies to battle."<<std::endl;
		return;
	}

	std::cout<<"\n\nTime for a battle!"<<std::endl;
	std::cout<<"You are up against: "<<std::endl;
	for (unsigned int i = 0; i<enemies.size(); ++i){
		std::cout<<i+1<<": "<<enemies[i]->type()<<" "<<enemies[i]->name()<<std::endl;
	}
	std::srand(time(NULL)); //generate different randomizations
	bool done_fighting  = false;
	int round = 1;
	while( ! done_fighting ){
		std::cout<<"\n\nRound "<<round++<<"!\n"<<std::endl;
		std::random_shuffle( enemies.begin(), enemies.end() ); //shuffle the order of enemies encounters
		for (auto iter = enemies.begin(); iter != enemies.end(); ++iter){
			Hero_->fight( *iter ); //one round
			if (Hero_->isDead()){
				done_fighting = true;
				break; //we are dead, don't fight anymore
			}
			if ( (*iter)->isDead() ){
				std::cout<< (*iter)->type() <<" "<< (*iter)->name() <<" fainted!"<<std::endl;
				//loot the enemy if possible
				if ( (*iter)->inventory ){
					std::vector< p_O > loot = (*iter)->inventory->loot();
					if (loot.size()>0){
						std::cout<< (*iter)->type() <<" "<< (*iter)->name() <<" dropped the following stuff:"<<std::endl;
						for (unsigned int i = 0; i<loot.size(); ++i){
							std::cout<<i+1<<": <"<<loot[i]->type()<<"> "<<loot[i]->name()<<std::endl;
						}
						Hero_->inventory->put_all(loot);
					}
				}
			}
		}
		//Erase-remove idiom to remove dead enemies
		enemies.erase( std::remove_if(std::begin(enemies), std::end(enemies),
				[](p_F const & enemy) -> bool {return enemy->isDead(); }), std::end(enemies) );

		if (enemies.empty()) done_fighting = true;
	}
	if ( Hero_->isDead() ){
		std::cout<<"You died in battle!"<<std::endl;
	}
	else{
		std::cout<<"All enemies are defeated!"<<std::endl;
	}
}

void TheGame::intro() const{
	std::vector<std::string> text_files_name;
	text_files_name.push_back("TheGame_textfiles/bg_story.txt");
	text_files_name.push_back("TheGame_textfiles/how_to_play.txt");
	std::string line;
	for (unsigned int i = 0; i<text_files_name.size(); ++i){
		std::ifstream file(text_files_name[i]);
		if (file.is_open()){
			while ( std::getline (file,line) ){
				std::cout<<line<<std::endl;
			}
			file.close();
		}
		else
			std::cout << "Unable to open file ./" << text_files_name[i] <<std::endl;

		std::cout<<std::endl<<std::endl;
	}
}

void TheGame::credits() const{

	std::string text_file_name = "TheGame_textfiles/credits.txt";
	std::string line;

	std::ifstream file(text_file_name);
	if (file.is_open()){
		while ( std::getline (file,line) ){
			std::cout<<line<<std::endl;
		}
		file.close();
	}
	else
		std::cout << "Unable to open file ./" << text_file_name <<std::endl;

	std::cout<<std::endl<<std::endl;
}

void TheGame::stage_1(){
	continue_game_ = true;
	bool special_event_has_happen = false;
	while (continue_game_){
		bool special_event = false;
		Hero_->do_battle = false;
		this->take_command();
		//talking to an Evil actor changes do_battle to true
		if(Hero_->do_battle){
			battle();
			//if you defeat the EvilCat in the mansion
			special_event = true;
		}
		if (Hero_->isDead()){
			continue_game_ = false;
			continue;
		}
		//special state, allow access to second floor
		if (special_event && !special_event_has_happen ){
			p_R mansion = std::move(all_rooms_.find("Mansion")->second);
			p_R second_floor = std::move(all_rooms_.find("Second floor")->second);
			mansion->link(second_floor);
			//put back the rooms
			all_rooms_.insert (std::pair< std::string, p_R >
				(mansion->name(),std::move(mansion)) );
			all_rooms_.insert (std::pair< std::string, p_R >
				(second_floor->name(),std::move(second_floor)) );

			std::cout<<"When the EvilCat fainted, a hidden stair appear!\n"
					<<"You have now access to the second floor of the mansion!" <<std::endl;
			special_event = false;
			special_event_has_happen = true;
		}
		//Stage 1 completed!
		if (current_room_->name() == "Second floor"){
			return; //go back to playTheGame()
		}
	}

}

void TheGame::stage_2(){
	continue_game_ = true;
	bool special_event_has_happen = false;
	while (continue_game_){
		bool special_event = false;

		Hero_->do_battle = false;
		this->take_command();
		//talking to an Evil actor changes do_battle to true
		if(Hero_->do_battle){
			std::cout<<"Will soon battle!"<<std::endl;
			battle();
			std::cout<<"have battled!"<<std::endl;
		}
		if (Hero_->isDead()){
			continue_game_ = false;
			continue;
		}

		if (Hero_->inventory->item_exist("Cat Key")){
			std::cout<<"I have the Cat Key! "<<std::endl;
			special_event = true;
		}

		//special state, allow access to the Cat Café
		if (special_event && !special_event_has_happen){
			std::cout<<"Inside special event!"<<std::endl;
			p_R mansion = std::move(all_rooms_.find("Mansion")->second);
			std::cout<<"A"<<std::endl;
			p_R cat_cafe = std::move(all_rooms_.find("Cat Café")->second);
			std::cout<<"B"<<std::endl;
			//cat café is an absorbing state
			mansion->link(cat_cafe);
			std::cout<<"C"<<std::endl;
			//put back the rooms
			all_rooms_.insert (std::pair< std::string, p_R >
				(mansion->name(),std::move(mansion)) );
			std::cout<<"D"<<std::endl;
			all_rooms_.insert (std::pair< std::string, p_R >
				(cat_cafe->name(),std::move(cat_cafe)) );

			std::cout<<"You heard a strange sound echoing inside the mansion!\n"
					<<"Could it perhaps be connected with this key we just got?" <<std::endl;
			special_event_has_happen = true;
		}
		//Stage 2 completed!
		if (current_room_->name() == "Cat Café"){
			return; //go back to playTheGame()
		}
	}
}

void TheGame::stage_cat_cafe(){
	//once we are in the cat café, we cannot go back
	continue_game_ = true;
	while (continue_game_){
		//The game will end when you type "I am home"
		this->take_command();
	}
}

void TheGame::meny(){
	bool continue_to_play = true;
	while (continue_to_play){
		std::cout<<"MAIN MENU\n\n\n"<<
				"Welcome to TheGame!\n"<<
				"Here are your options:\n"
				"1: Play TheGame\n"
				"0: Quit"<<std::endl;
		int int_answer = 0;
		bool is_incorrect = true;
		while (is_incorrect) {
			std::cout << "Please enter 1 or 0..."<<std::endl;
			int_answer = this->read_int();
			if (int_answer >= 0 && int_answer <=1){
				is_incorrect = false;
				continue;
			}
			std::cout<<"Not a number between 1 and 0!"<<std::endl;
		}
		if (int_answer == 0){
			std::cout<<"Good bye!"<<std::endl;
			continue_to_play = false;
			continue;
		}
		if (int_answer == 1){
			this->playTheGame();
		}
	}


}
//////////////////////////////////////////////////////////////////////
void TheGame::playTheGame(){
	intro();
	stage_1();
	if (Hero_->isDead()){
		std::cout<<"\n\nGAME OVER!\n\n"<<std::endl;
		return;
	}
	stage_2();
	if (Hero_->isDead()){
		std::cout<<"\n\nGAME OVER!\n\n"<<std::endl;
		return;
	}
	stage_cat_cafe();
	credits();
}
