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

	std::cout<<"\n------------Testing Room-class!------------"<<std::endl;

	std::vector< std::shared_ptr<Room> > rooms_1;
	std::vector< std::shared_ptr<Room> > rooms_2;
	std::vector< std::shared_ptr<Room> > all_rooms;

	std::shared_ptr<Room> r1(new Room("Level 1"));
	std::shared_ptr<Room> r2(new Room("Level 2"));
	std::shared_ptr<Room> r3(new Room("Level 3"));

	//inserting stuff to the rooms
	std::unique_ptr<Object> item_1(new Item("Google glass", "Glasses to translate japanese to english") );
	std::unique_ptr<Object> item_2(new Weapon("Sword", "A long broad sword", 10,1) );
	r1->put(std::move(item_1));
	r1->put(std::move(item_2));

	//inserting actors into rooms
	std::unique_ptr<Animal> actor_1(new EvilCat("MadCat") );
	std::unique_ptr<Animal> actor_2(new Cat("Siamese") );
	std::unique_ptr<Robot> actor_3(new CafeRobot("Bob") );
	std::unique_ptr<Object> temp_wep1(new Weapon("Axe", "Heavy Axe", 10,3));
	std::unique_ptr<Robot> actor_4(new EvilRobot("PetaMan", 10, std::move(temp_wep1)) );

	std::cout<<"\n\nINSERTING ACTORS!!"<<std::endl;
	r1->put_robot( std::move(actor_3) );
	r1->put_animal(std::move(actor_2) );
	r1->put_animal( std::move(actor_1) );
	r3->put_robot( std::move(actor_4) );


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
	std::shared_ptr<Room> currentRoom = all_rooms[0] ;

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
	std::unique_ptr<Object> get_item_1 = currentRoom->take("Google glass");
	std::unique_ptr<Object> get_item_2 = currentRoom->take("Sword");
	std::unique_ptr<Object> get_item_3 = currentRoom->take("Derp"); //nullptr
	std::cout<<"get_item_1:"<<std::endl;
	std::cout<<*get_item_1<<std::endl;
	std::cout<<"get_item_2:"<<std::endl;
	std::cout<<*get_item_2<<std::endl;

	std::cout<<"\nGet actors from current room..."<<std::endl;
	auto get_robot_1 = currentRoom->take_robot("Bob");
	std::cout<<"get_robot_1:"<<std::endl;
	std::cout<<*get_robot_1<<std::endl;

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

#endif /* TESTING_HPP_ */
