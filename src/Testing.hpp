/*
 * Testing.hpp
 *
 *  Created on: 23 feb 2014
 *      Author: findus
 */

#ifndef TESTING_HPP_
#define TESTING_HPP_


#include "Cat.hpp"
#include "EvilCat.hpp"
#include "Item.hpp"
#include "Weapon.hpp"
#include "CafeRobot.hpp"
#include "EvilRobot.hpp"
#include "Room.hpp"
#include "Player.hpp"

void test_Room(){
	using UP_F = std::unique_ptr<Fighter>;
	using UP_O = std::unique_ptr<Object>;
	using SP_R = std::shared_ptr<Room>;

	std::cout<<"\n------------Testing Room-class!------------"<<std::endl;

	std::vector< SP_R > rooms_1;
	std::vector< SP_R > rooms_2;
	std::vector< SP_R > all_rooms;

	SP_R r1(new Room("Level 1"));
	SP_R r2(new Room("Level 2"));
	SP_R r3(new Room("Level 3"));

	//inserting stuff to the rooms
	UP_O item_1(new Item("Google glass", "Glasses to translate japanese to english") );
	UP_O item_2(new Weapon("Sword", "A long broad sword", 10,1) );
	r1->put(std::move(item_1));
	r1->put(std::move(item_2));

	//inserting actors into rooms
	UP_F actor_1(new EvilCat("MadCat") );
	UP_F actor_2(new Cat("Siamese") );
	UP_F actor_3(new CafeRobot("Bob") );
	UP_O temp_wep1(new Weapon("Axe", "Heavy Axe", 10,3));
	UP_F actor_4(new EvilRobot("PetaMan", 10, std::move(temp_wep1)) );

	std::cout<<"\n\nINSERTING ACTORS!!"<<std::endl;
	r1->enter( std::move(actor_3) );
	r1->enter( std::move(actor_2) );
	r1->enter( std::move(actor_1) );
	r3->enter( std::move(actor_4) );


	rooms_1.push_back(r2);
	rooms_1.push_back(r3);
	rooms_2.push_back(r3);
	all_rooms.push_back(r1);
	all_rooms.push_back(r2);
	all_rooms.push_back(r3);

	r1->link(rooms_1);
	r2->link_exit(r1);
	r2->link(rooms_2);
	r3->link_exit(r2);

	//start in room 1
	SP_R currentRoom = all_rooms[0] ;

	std::cout<<"Calling description() on all rooms..."<<std::endl;
	for (unsigned int i = 0; i<all_rooms.size(); ++i)
		all_rooms[i]->description();

	std::cout<<"Calling directions() on all rooms..."<<std::endl;
	for (unsigned int i = 0; i<all_rooms.size(); ++i)
		all_rooms[i]->directions();


	std::cout<<"\nEnter room 2 from room 1..."<<std::endl;
	currentRoom = currentRoom->neighbor(1);
	std::cout<<"currentRoom: "<<currentRoom->name()<<std::endl;
	std::cout<<"call currentRoom->directions()..."<<std::endl;
	currentRoom->directions();
	std::cout<<"\nGoing back from room 2 (currentRoom) to room 1..."<<std::endl;
	currentRoom = currentRoom->exit_room();
	std::cout<<"currentRoom: "<<currentRoom->name()<<std::endl;
	std::cout<<"call currentRoom->directions()..."<<std::endl;
	currentRoom->directions();

	std::cout<<"Calling description() on all rooms..."<<std::endl;
	for (unsigned int i = 0; i<all_rooms.size(); ++i)
		all_rooms[i]->description();

	std::cout<<"\nGet items from current room..."<<std::endl;
	UP_O get_item_1 = currentRoom->take("Google glass");
	UP_O get_item_2 = currentRoom->take("Sword");
	UP_O get_item_3 = currentRoom->take("Derp"); //nullptr
	std::cout<<"get_item_1:"<<std::endl;
	std::cout<<*get_item_1<<std::endl;
	std::cout<<"get_item_2:"<<std::endl;
	std::cout<<*get_item_2<<std::endl;

	std::cout<<"\nGet actors from current room..."<<std::endl;
	UP_F get_robot_1 = currentRoom->leave("Bob");
	std::cout<<"get_robot_1:"<<std::endl;
	get_robot_1->talk();


	std::cout<<"Calling description() on all rooms again..."<<std::endl;
	for (unsigned int i = 0; i<all_rooms.size(); ++i){
		all_rooms[i]->description();
	}
}
//////////////////////////////////////////////////////////////////
void test_Player(){
	std::unique_ptr<Player> p1(new Player("Martin"));
	p1->stats();
	std::unique_ptr<Object> temp_wep1(new Weapon("Axe", "Heavy Axe", 10,3));
	p1->equip_RH(std::move(temp_wep1));
	p1->stats();
	p1->show_inventory();
}
//////////////////////////////////////////////////////////////////
void test_attack(){
	std::unique_ptr<Fighter> er1(new EvilRobot("Evil Asimo"));
	std::string input = "";
	int temp = er1->attack();
	std::cout<<"attack returned "<<temp<<std::endl;
	std::getline(std::cin, input);
	temp = er1->attack();
	std::cout<<"attack returned "<<temp<<std::endl;
	std::getline(std::cin, input);
	temp = er1->attack();
	std::cout<<"attack returned "<<temp<<std::endl;
	std::getline(std::cin, input);
	temp = er1->attack();
	std::cout<<"attack returned "<<temp<<std::endl;
	std::getline(std::cin, input);
	temp = er1->attack();
	std::cout<<"attack returned "<<temp<<std::endl;
	std::getline(std::cin, input);

}
//////////////////////////////////////////////////////////////////
void test_FighterVector(){
	using FP = std::unique_ptr<Fighter>;
	using OP = std::unique_ptr<Object>;
	FP actor_1(new EvilCat("MadCat") );
	FP actor_2(new Cat("Siamese") );
	FP actor_3(new CafeRobot("Bob") );
	OP temp_wep1(new Weapon("Axe", "Heavy Axe", 10,3));
	FP actor_4(new EvilRobot("PetaMan", 10, std::move(temp_wep1)) );
	FP actor_5(new Player("Andreas"));

	std::vector<FP> T;
	T.push_back(std::move(actor_1));
	T.push_back(std::move(actor_2));
	T.push_back(std::move(actor_3));
	T.push_back(std::move(actor_4));
	T.push_back(std::move(actor_5));

	for (unsigned int i=0; i< T.size(); ++i){
		std::cout<<T[i]->name()<<std::endl;
		std::cout<<T[i]->type()<<std::endl;
		std::cout<<T[i]->baseType()<<std::endl;
		std::cout<<T[i]->current_HP()<<std::endl;
		T[i]->takeDamage(1);
		std::cout<<T[i]->current_HP()<<std::endl;
		T[i]->talk();
		int temp = T[i]->attack();
		std::cout<<"attack: "<<temp<<std::endl;
		std::cout<<"----------------------------"<<std::endl;
	}
}

#endif /* TESTING_HPP_ */
