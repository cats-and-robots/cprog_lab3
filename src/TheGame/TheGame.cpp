/*
 * TheGame.cpp
 *
 *  Created on: 1 mar 2014
 *      Author: findus
 */

#include "TheGame.hpp"

TheGame::TheGame(){
	played_before_ = false;

	//constructor gives warnings if we don't assign the attributes
	continue_game_ = true;
	special_event_1_has_happened_ = false;
	special_event_2_has_happened_ = false;
	cleared_stage_1_ = false;
	cleared_stage_2_ = false;


}

TheGame::~TheGame(){}

void TheGame::create_new_game(){

	//clear all smart pointers and maps (in case we re-play the game)
	Hero_.reset();
	current_room_.reset();
	all_rooms_.clear();
	//if we have not loaded the commands, do it
	if (cmds_.empty()){
		load_cmds();
	}
	//set the different passed stages and special events
	continue_game_ = true;
	special_event_1_has_happened_ = false;
	special_event_2_has_happened_ = false;
	cleared_stage_1_ = false;
	cleared_stage_2_ = false;



	//create items and weapons
	p_O google_glass(new Item("Google Glass", "Device to help you translate japanese to english", "google glass"));
	p_O key_to_mansion(new Item("Rusty Key", "Key that allows access to the mansion", "mansion key"));
	p_O key_to_bathroom(new Item("Small Key", "It says \"お手洗い\". O..te..ara..i..?", "bathroom key"));
	p_O key_to_cat_cafe(new Item("Cat Key", "Key that is shaped like a cat", "cat key"));
	p_O small_knife(new Weapon("Small Knife", "A small kitchen knife", 2,0));
	p_O heavy_axe(new Weapon("Heavy Axe", "A big powerful axe", 15,0));
	p_O iron_shield(new Weapon("Iron Shield", "Good shield for defending yourself against animal claws", 0,2));
	p_O small_potion(new Potion("Small Potion", "Restores a small amount of your health", 30));
	p_O expired_milk(new Potion("Expired Milk", "Says that it expired 2012...eeuuhh", -30));

	//Create rooms
	p_R entrance(new Room("Entrance"));
	p_R mansion(new Room("Mansion", false, key_to_mansion->use_code() ));
	p_R cat_cafe(new Room("Cat Cafe", false, key_to_cat_cafe->use_code() ));
	p_R second_floor(new Room("Second floor"));
	p_R bathroom(new Room("Bathroom", false, key_to_bathroom->use_code() ));


	//Create player and actors

	p_P tmp(new Player("Hero"));
	Hero_ = std::move(tmp);
	p_C guardian_cat(new GuardianCat("Siamese", google_glass->use_code()));
	p_C grumpy_persian(new EvilCat("Grumpy Persian"));
	p_C dark_asimo(new EvilRobot("Dark Asimo"));
	p_C devon_rex(new EvilCat("Devon Rex", 50 , 20, 3));
	p_C dark_petman(new EvilRobot("Dark PETMAN", 3));
	p_C munchkin(new Cat("Munchkin"));
	p_C scottish_fold(new Cat("Scottish Fold"));
	p_C nao(new CafeRobot("Nao"));

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
	this->put_room(std::move(entrance));
	this->put_room(std::move(mansion));
	this->put_room(std::move(cat_cafe));
	this->put_room(std::move(second_floor));
	this->put_room(std::move(bathroom));

	//Set the Hero's name
	set_hero_name();

	//Show the intro-text
	intro();
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
	//Write "I am home" in the Cat Cafe to finish the game
	if (input == "I am home" && current_room_->name()== "Cat Cafe") {
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
	std::vector<p_C> enemies = current_room_->leave_all_evil();
	if (enemies.size()==0){
		std::cout<<"No enemies to battle."<<std::endl;
		return;
	}

	std::cout<<"\n\nTime for a battle!"<<std::endl;
	std::cout<<"You are up against: "<<std::endl;
	for (unsigned int i = 0; i<enemies.size(); ++i){
		std::cout<<"   <"<<enemies[i]->type()<<"> "<<enemies[i]->name()<<std::endl;
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
				done_fighting = true; //end the battle
				break; //we are dead, don't fight anymore enemies
			}
			if ( (*iter)->isDead() ){
				std::cout<<"\n<"<< (*iter)->type() <<"> "<< (*iter)->name() <<" fainted!"<<std::endl;
				std::cout<<"Hit enter to continue";
				std::cin.ignore();
				//loot the enemy if possible
				if ( (*iter)->inventory ){
					std::vector< p_O > loot = (*iter)->inventory->loot();
					if (loot.size()>0){
						std::cout<<"\n<"<< (*iter)->type() <<"> "<< (*iter)->name() <<" dropped the following stuff:"<<std::endl;
						for (unsigned int i = 0; i<loot.size(); ++i){
							std::cout<<"   <"<<loot[i]->type()<<"> "<<loot[i]->name()<<std::endl;
						}
						Hero_->inventory->put_all(loot);
						std::cout<<"Hit enter to continue";
						std::cin.ignore();
					}
				}
			}
		}
		//Erase-remove idiom to remove dead enemies
		enemies.erase( std::remove_if(std::begin(enemies), std::end(enemies),
				[](p_C const & enemy) -> bool {return enemy->isDead(); }), std::end(enemies) );

		//when we have defeated all enemies, the battle is over
		if (enemies.empty()) done_fighting = true;
	}
	if ( Hero_->isDead() ){
		//if we died, fully restore all remaining enemies
		for (auto iter = enemies.begin(); iter != enemies.end(); ++iter){
			(*iter)->full_restore();
		}
		//put the enemies back in the current room
		current_room_->enter_all(enemies);

		std::cout<<"\nYou died in battle!"<<std::endl;
		std::cout<<"Hit enter to continue";
		std::cin.ignore();
	}
	else{
		std::cout<<"\nAll enemies are defeated!"<<std::endl;
		std::cout<<"Hit enter to continue";
		std::cin.ignore();
	}
}
void TheGame::put_room(p_R room){
	all_rooms_.insert (std::pair< std::string, std::shared_ptr<Room> >
		(room->name(),std::move(room)) );
}

p_R TheGame::take_room(std::string name){
	for (auto iter = all_rooms_.find(name); iter != all_rooms_.end(); ++iter){
		if (iter->first == name){
			p_R room = std::move(iter->second);
			all_rooms_.erase(iter);
			return std::move(room);
		}
	}
	return nullptr;
}

void TheGame::intro() const{
	std::cout<<"\n\n";
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

		std::cout<<"\n\n";
	}
}

void TheGame::credits() const{

	std::cout<<"\n\n";
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

	std::cout<<"\n\n";
	std::cout<<"Hit enter to go back to the menu";
	std::cin.ignore();
}

void TheGame::set_hero_name(){
	std::cout<<"Please enter the name of our Hero!"<<std::endl;
	std::string name = this->read_string();
	Hero_->change_name(name);
}

void TheGame::stage_1(){
	continue_game_ = true;
	while (continue_game_){
		bool special_event = false;
		Hero_->do_battle = false;
		this->take_command();
		//talking to an Evil actor changes do_battle to true
		if(Hero_->do_battle){
			battle();
		}
		if (Hero_->isDead()){
			continue_game_ = false;
			continue;
		}
		if (current_room_->name() == "Mansion" && current_room_->no_enemies()){
			//if you defeat the EvilCat in the mansion
			special_event = true;
		}
		//special state, allow access to second floor
		if (special_event && !special_event_1_has_happened_ ){

			special_event_1_has_happened_ = true;

			p_R mansion = this->take_room("Mansion");
			if (!mansion) std::cout<<"Could not get Mansion!"<<std::endl;

			p_R second_floor = this->take_room("Second floor");
			if (!second_floor) std::cout<<"Could not get Second floor!"<<std::endl;
			mansion->link(second_floor);
			//put back the rooms
			this->put_room(std::move(mansion));
			this->put_room(std::move(second_floor));

			std::cout<<"\nWhen the EvilCat fainted, a hidden door appeared!\n"
					<<"You have now access to the second floor of the mansion!" <<std::endl;

		}
		//Stage 1 completed!
		if (current_room_->name() == "Second floor"){
			return; //go back to playTheGame()
		}
	}

}

void TheGame::stage_2(){
	continue_game_ = true;
	while (continue_game_){
		bool special_event = false;

		Hero_->do_battle = false;
		this->take_command();
		//talking to an Evil actor changes do_battle to true
		if(Hero_->do_battle){
			battle();
		}
		if (Hero_->isDead()){
			continue_game_ = false;
			continue;
		}
		if (current_room_->name() == "Bathroom" && current_room_->no_enemies()){
			//if you defeated the EvilCat and EvilRobot in the bathroom
			special_event = true;
		}

		//special state, allow access to the Cat Cafe
		if (special_event && !special_event_2_has_happened_){

			special_event_2_has_happened_ = true;

			p_R mansion = this->take_room("Mansion");
			if (!mansion) std::cout<<"Could not get Mansion!"<<std::endl;

			p_R cat_cafe = this->take_room("Cat Cafe");
			if (!cat_cafe) std::cout<<"Could not get Cat Cafe!"<<std::endl;

			//Cat Cafe is an absorbing state
			mansion->link(cat_cafe);

			//put back the rooms
			this->put_room(std::move(mansion));
			this->put_room(std::move(cat_cafe));

			std::cout<<"\nYou heard a strange sound echoing inside the mansion!\n"
					<<"Could it perhaps be connected with the key "<< Hero_->name() <<" just got?" <<std::endl;
		}
		//Stage 2 completed!
		if (current_room_->name() == "Cat Cafe"){
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

void TheGame::playTheGame(){
	if (!cleared_stage_1_){
		stage_1();
		if (Hero_->isDead()){
			std::cout<<"\n\nGAME OVER!"<<std::endl;
			std::cout<<"Hit enter to go back to main menu";
			std::cin.ignore();
			std::cout<<"\n\n\n"<<std::endl;
			return;
		}
		cleared_stage_1_ = true;
	}
	if (!cleared_stage_2_){
		stage_2();
		if (Hero_->isDead()){
			std::cout<<"\n\nGAME OVER!"<<std::endl;
			std::cout<<"Hit enter to go back to main menu";
			std::cin.ignore();
			std::cout<<"\n\n\n"<<std::endl;
			return;
		}
		cleared_stage_2_ = true;
	}
	stage_cat_cafe();
	credits();
}
//////////////////////////////////////////////////////////////////////

void TheGame::meny(){
	bool continue_to_play = true;
	while (continue_to_play){
		std::cout<<"MAIN MENU\n\n\n"<<
				"Welcome to TheGame!\n"<<
				"Here are your options:\n"
				"1: Start a new game\n"<<
				"2: Continue\n"<<
				"0: Quit"<<std::endl;
		int int_answer = 0;
		bool is_incorrect = true;
		while (is_incorrect) {
			std::cout << "Please enter 1, 2 or 0..."<<std::endl;
			int_answer = this->read_int();

			if (int_answer<0 || int_answer >2){
				std::cout<<"Not a number between 0 and 2!"<<std::endl;
				continue;
			}
			if (int_answer == 2 && played_before_ == false){
				std::cout<<"You have not played the game before so you cannot choose to continue!"<<std::endl;
				continue;
			}
			else{
				is_incorrect = false;
				continue;
			}

		}
		if (int_answer == 0){
			std::cout<<"Good bye!"<<std::endl;
			continue_to_play = false;
			continue;
		}
		else if (int_answer == 1){
			this->create_new_game();
			this->playTheGame();
			played_before_ = true;
		}
		else if (int_answer == 2){
			Hero_->full_restore();
			std::cout<<"\nRespawn in the same room your currently were in!\n"<<
					"Defeated enemies will not respawn!\n"<<std::endl;
			this->playTheGame();
		}
	}


}
