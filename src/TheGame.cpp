/*
 * TheGame.cpp
 *
 *  Created on: 1 mar 2014
 *      Author: findus
 */

#include "TheGame.hpp"

TheGame::TheGame(){
	std::cout<<"Created a TheGame object!"<<std::endl;
	sp_R entrance(new Room("Entrance"));
	sp_R main_hall(new Room("Main hall"));
	sp_R cat_cafe(new Room("Cat Café"));
	sp_R second_floor(new Room("Second floor"));
	sp_R bathroom(new Room("Bathroom"));

	entrance->link(main_hall);
	main_hall->link(cat_cafe);
	main_hall->link(second_floor);
	main_hall->link_exit(entrance);
	cat_cafe->link_exit(main_hall);
	second_floor->link(bathroom);
	second_floor->link_exit(main_hall);
	bathroom->link_exit(second_floor);

	currentRoom_ = entrance;

}

TheGame::~TheGame() {
	std::cout<<"Destroyed a TheGame object!"<<std::endl;
}

void TheGame::playTheGame(){
	std::cout<<"PUT IN GAME LOGIC HERE!!!"<<std::endl;
	currentRoom_->description();
	currentRoom_->directions();
}
