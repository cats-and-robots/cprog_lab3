/*
 * Room.hpp
 *
 *  Created on: 17 feb 2014
 *      Author: findus
 */

#ifndef ROOM_HPP_
#define ROOM_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <map> //for map


#include "EvilRobot.hpp"
#include "CafeRobot.hpp"
#include "EvilCat.hpp"
#include "Inventory.hpp"



class Room:public Inventory {

private:
	std::vector< std::shared_ptr<Room> > neighbors_;
	std::weak_ptr<Room> exit_;
	std::string name_;
	std::map<std::string, std::unique_ptr<Animal> > animals_;
	std::map<std::string, std::unique_ptr<Robot>  > robots_;

public:

	//creating a room
	Room(std::string name):name_(name){
		std::cout<<"Created "<< this->type() << " " << this->name() << "!"<<std::endl;
	}

	virtual ~Room(){
		std::cout<<"Destroyed "<< this->type() << " " << this->name() << "!"<<std::endl;
	}

	std::string name() const{return name_;}

	std::string type() const{return "Room";}

	//creating the starting room
	void link(const std::vector< std::shared_ptr<Room> > & rooms){
		neighbors_ = rooms;
	}

	//creating the other rooms, give also the exit room
	void link_exit(const std::shared_ptr<Room> & exitRoom){
		exit_ = exitRoom;
	}

	void directions() const {
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

	void description() const{
		std::cout<<"Inside "<< this->name()<<" can the following things be seen..." <<std::endl;

		std::cout<<"\n";
		this->show_inventory();
		std::cout<<"\n";
		int counter;
		if (animals_.size()>0){
			if (animals_.size() == 1)
				std::cout<<"One animal:"<<std::endl;
			else
				std::cout<<"Several animals:"<<std::endl;
			counter = 1;
			for (auto iter = animals_.begin(); iter != animals_.end(); ++iter){
				std::cout<< counter++ <<": "<<iter->first<<std::endl;
			}
		}
		else
			std::cout<<"There are no animals..."<<std::endl;
		std::cout<<"\n";
		if (robots_.size()>0){
			if (robots_.size() == 1)
				std::cout<<"One robot:"<<std::endl;
			else
				std::cout<<"Several robots:"<<std::endl;
			counter = 1;
			for (auto iter = robots_.begin(); iter != robots_.end(); ++iter){
				std::cout<< counter++ <<": "<<iter->first<<std::endl;
			}
		}
		else
			std::cout<<"There are no robots..."<<std::endl;
		std::cout<<"\n";
		std::cout<<"--------------------------------------------"<<std::endl;
	}

	std::shared_ptr<Room> neighbor(int room_nr){
		unsigned int index = room_nr-1;
		if (index > neighbors_.size() || index < 0)
			return nullptr;
		else
			return neighbors_[index];
	}

	std::shared_ptr<Room> exit_room(){
		if (exit_.use_count() > 0)
			return exit_.lock();
		else
			return nullptr;
	}

	void put_animal(std::unique_ptr<Animal> ani){
		//		http://stackoverflow.com/questions/6952486/recommended-way-to-insert-elements-into-map
		//		Also, if your class has no default constructror, you are forced to use insert
		std::cout<<"Inserted "<<ani->type() <<" "<<ani->name()<<"!"<<std::endl;
		animals_.insert (std::pair< std::string, std::unique_ptr<Animal> >
			(ani->name(),std::move(ani)) );
	}
	void put_robot(std::unique_ptr<Robot> rob){
		std::cout<<"Inserted "<<rob->type() <<" "<<rob->name()<<"!"<<std::endl;
		robots_.insert (std::pair< std::string, std::unique_ptr<Robot> >
			(rob->name(),std::move(rob)) );
	}

	std::unique_ptr<Animal> take_animal(std::string name){
		for (auto iter = animals_.find(name); iter != animals_.end(); ++iter){
			if (iter->first == name){
				std::unique_ptr<Animal> thing = std::move(iter->second);
				animals_.erase(iter);
				return std::move(thing);
			}
		}
		return nullptr;
	}
	std::unique_ptr<Robot> take_robot(std::string name){
		for (auto iter = robots_.find(name); iter != robots_.end(); ++iter){
			if (iter->first == name){
				std::unique_ptr<Robot> thing = std::move(iter->second);
				robots_.erase(iter);
				return std::move(thing);
			}
		}
		return nullptr;
	}



};



#endif /* ROOM_HPP_ */
