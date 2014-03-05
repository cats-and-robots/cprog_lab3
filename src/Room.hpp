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
	std::map<std::string, std::unique_ptr<Fighter> > actors_;

public:
	Room(std::string);
	virtual ~Room();

	std::string name() const;
	std::string type() const;

	void link(const std::shared_ptr<Room> & );
	void link_exit(const std::shared_ptr<Room>& );
	void directions() const;
	void description() const;

	std::shared_ptr<Room> neighbor(const std::string);
	std::shared_ptr<Room> exit_room();

	void enter(std::unique_ptr<Fighter> );
	void enter_all(std::vector< std::unique_ptr<Fighter> > &);
	std::unique_ptr<Fighter> leave(std::string name);
	std::vector< std::unique_ptr<Fighter> > leave_all();
	std::vector< std::unique_ptr<Fighter> > leave_all_evil();

};



#endif /* ROOM_HPP_ */
