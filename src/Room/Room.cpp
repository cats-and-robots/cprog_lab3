/*
 * Room.cpp
 *
 *  Created on: 17 feb 2014
 *      Author: findus
 */

#include "Room.hpp"

Room::Room(std::string name):
name_(name), allowed_entrance_(true), use_code_("_") {}

Room::Room(std::string name, bool room_access, std::string use_code):
name_(name), allowed_entrance_(room_access), use_code_(use_code) {}

Room::~Room(){}

std::string Room::name() const{
	return name_;
}

std::string Room::type() const{
	return "Room";
}


void Room::link(const std::shared_ptr<Room>  & room){
	neighbors_.push_back(room);
}

void Room::link_exit(const std::shared_ptr<Room> & exitRoom){
	exit_ = exitRoom;
}

void Room::directions() const {
	if (neighbors_.size() > 0){
		std::cout<<"\n";
		if (neighbors_.size() == 1)
			std::cout<<"You have a door in front of you with a text that says:"<<std::endl;
		else
			std::cout<<"You have several doors in front of you with texts that says:"<<std::endl;
		for (unsigned int i=0; i<neighbors_.size(); ++i){
			std::cout<<"   "<< neighbors_[i]->name() <<std::endl;
		}
	}

	if (exit_.use_count() > 0){
		std::cout<<"\n";
		std::cout<<"There is a door behind you with a text that says:"<<std::endl;
		std::cout<<"   "<<exit_.lock()->name()<<std::endl;
	}

	if (neighbors_.size() <= 0 && exit_.use_count() <= 0){
		std::cout<<"\n";
		std::cout<<"The door behind you have vanished!\nYou are stuck inside this room!"<<std::endl;
	}
}

void Room::description() const{
	std::cout<<"Inside "<< this->name()<<" can the following things be seen..." <<std::endl;


	//if there are items inside the room, show them
	if (! this->isEmpty()){
		std::cout<<"\n";
		if(this->items_.size()==1)
			std::cout<<"One object:"<<std::endl;
		else
			std::cout<<"Several objects:"<<std::endl;
		this->show_inventory();
	}

	if (actors_.size()>0){
		std::cout<<"\n";
		if (actors_.size() == 1)
			std::cout<<"One character:"<<std::endl;
		else
			std::cout<<"Several characters:"<<std::endl;
		for (auto iter = actors_.begin(); iter != actors_.end(); ++iter){
			std::cout<<"   <"<< iter->second->type()<<"> "<<iter->first<<std::endl;
		}
	}
	if (this->isEmpty() && actors_.size() == 0) {
		std::cout<<"\n";
		std::cout<<"   Nothing..."<<std::endl;
	}
}

std::string Room::get_use_code() const{
	return use_code_;
}

bool Room::is_entrance_allowed() const{
	return allowed_entrance_;
}

void Room::set_allowed_entrance(bool access){
	allowed_entrance_ = access;
}

bool Room::use_item(std::string use_code){
	//check if the item's code can be used for the room we are currently in
	if (this->get_use_code() == use_code){
		allowed_entrance_ = true;
		return true;
	}

	else{
		//check if it can be used on a character in the room
		for (auto iter = actors_.begin(); iter != actors_.end(); ++iter){
			if ( iter->second->use(use_code) ){
				return true;
			}
		}

		//check if it can be used to unlock a neighbor area
		for (unsigned int i = 0; i<neighbors_.size(); ++i){
			if (neighbors_[i]->get_use_code() == use_code){
				neighbors_[i]->set_allowed_entrance(true);
				return true;
			}
		}
	}
	//if we got here, then the item's code could not be used in this area on anything!
	return false;
}


std::shared_ptr<Room> Room::neighbor(const std::string name){
	for (unsigned int i = 0; i<neighbors_.size(); ++i){
		if (name == neighbors_[i]->name())
			return neighbors_[i];
	}
	return nullptr;
}

std::shared_ptr<Room> Room::exit_room(){
	if (exit_.use_count() > 0)
		return exit_.lock();
	else
		return nullptr;
}

void Room::enter(std::unique_ptr<Character> actor){
	//		http://stackoverflow.com/questions/6952486/recommended-way-to-insert-elements-into-map
	//		Also, if your class has no default constructror, you are forced to use insert
	actors_.insert (std::pair< std::string, std::unique_ptr<Character> >
		(actor->name(),std::move(actor)) );
}

void Room::enter_all(std::vector< std::unique_ptr<Character> >& actors){
	while(!actors.empty()){
		this->enter( std::move( actors.back() ) );
		actors.pop_back();
	}
}

std::unique_ptr<Character> Room::leave(std::string name){
	for (auto iter = actors_.find(name); iter != actors_.end(); ++iter){
		if (iter->first == name){
			std::unique_ptr<Character> actor = std::move(iter->second);
			actors_.erase(iter);
			return std::move(actor);
		}
	}
	return nullptr;
}

std::vector< std::unique_ptr<Character> > Room::leave_all(){
	std::vector< std::unique_ptr<Character> > actors;
	std::vector< std::string > actors_name;
	for (auto iter = actors_.begin(); iter != actors_.end(); ++iter){
		actors_name.push_back(iter->first);
	}
	for (auto iter_name = actors_name.begin(); iter_name != actors_name.end(); ++iter_name){
		actors.push_back(this->leave(*iter_name));
	}
	return actors;
}

std::vector< std::unique_ptr<Character> > Room::leave_all_evil(){
	std::vector< std::unique_ptr<Character> > actors;
	std::vector< std::string > actors_name;
	for (auto iter = actors_.begin(); iter != actors_.end(); ++iter){
		if (iter->second->type() == "EvilCat" || iter->second->type() == "EvilRobot")
			actors_name.push_back(iter->first);
	}
	for (auto iter_name = actors_name.begin(); iter_name != actors_name.end(); ++iter_name){
		actors.push_back(this->leave(*iter_name));
	}
	return actors;
}

bool Room::no_enemies() const{
	int nr_found = 0;
	for (auto iter = actors_.begin(); iter != actors_.end(); ++iter){
		if (iter->second->type() == "EvilCat" || iter->second->type() == "EvilRobot")
			++nr_found;
	}
	if (nr_found == 0) return true;
	else return false;
}
