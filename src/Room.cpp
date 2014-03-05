/*
 * Room.cpp
 *
 *  Created on: 17 feb 2014
 *      Author: findus
 */

#include "Room.hpp"

Room::Room(std::string name):name_(name){}

Room::~Room(){ std::cout<<"Destroyed Room "<<name()<<std::endl;}

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
		if (neighbors_.size() == 1)
			std::cout<<"You have the following door in front of you:"<<std::endl;
		else
			std::cout<<"You have the following doors in front of you:"<<std::endl;
		for (unsigned int i=0; i<neighbors_.size(); ++i){
			std::cout<<i+1 <<": "<< neighbors_[i]->name() <<std::endl;
		}
	}
	else std::cout<<"There are no doors in front of you"<<std::endl;
	if (exit_.use_count() > 0){
		std::cout<<"There is a door behind you leading back to"<<std::endl;
		std::cout<<exit_.lock()->name()<<std::endl;
	}
	else std::cout<<"There is no door behind you"<<std::endl;
}

void Room::description() const{
	std::cout<<"Inside "<< this->name()<<" can the following things be seen..." <<std::endl;

	std::cout<<"\n";
	this->show_inventory();
	std::cout<<"\n";
	int counter;
	if (actors_.size()>0){
		if (actors_.size() == 1)
			std::cout<<"One creature:"<<std::endl;
		else
			std::cout<<"Several creatures:"<<std::endl;
		counter = 1;
		for (auto iter = actors_.begin(); iter != actors_.end(); ++iter){
			std::cout<< counter++ <<": "<<iter->first<<std::endl;
		}
	}
	else
		std::cout<<"There are no creatures..."<<std::endl;
	std::cout<<"\n";
	std::cout<<"--------------------------------------------"<<std::endl;
}

std::shared_ptr<Room> Room::neighbor(const std::string name){
	for (unsigned int i = 0; i<neighbors_.size(); ++i){
		if (name == neighbors_[i]->name())
			return neighbors_[i];
	}
	return nullptr;
//	unsigned int index = room_nr-1;
//	if (index > neighbors_.size() || index < 0)
//		return nullptr;
//	else
//		return neighbors_[index];
}

std::shared_ptr<Room> Room::exit_room(){
	if (exit_.use_count() > 0)
		return exit_.lock();
	else
		return nullptr;
}

void Room::enter(std::unique_ptr<Fighter> actor){
	//		http://stackoverflow.com/questions/6952486/recommended-way-to-insert-elements-into-map
	//		Also, if your class has no default constructror, you are forced to use insert
	actors_.insert (std::pair< std::string, std::unique_ptr<Fighter> >
		(actor->name(),std::move(actor)) );
}

void Room::enter_all(std::vector< std::unique_ptr<Fighter> >& actors){
	while(!actors.empty()){
		this->enter( std::move( actors.back() ) );
		actors.pop_back();
	}
}

std::unique_ptr<Fighter> Room::leave(std::string name){
	for (auto iter = actors_.find(name); iter != actors_.end(); ++iter){
		if (iter->first == name){
			std::unique_ptr<Fighter> actor = std::move(iter->second);
			actors_.erase(iter);
			return std::move(actor);
		}
	}
	return nullptr;
}

std::vector< std::unique_ptr<Fighter> > Room::leave_all(){
	std::vector< std::unique_ptr<Fighter> > actors;
	std::vector< std::string > actors_name;
	for (auto iter = actors_.begin(); iter != actors_.end(); ++iter){
		actors_name.push_back(iter->first);
	}
	for (auto iter_name = actors_name.begin(); iter_name != actors_name.end(); ++iter_name){
		actors.push_back(this->leave(*iter_name));
	}
	return actors;
}
