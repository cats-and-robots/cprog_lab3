/*
 * TheGame.hpp
 *
 *  Created on: 1 mar 2014
 *      Author: findus
 */

#ifndef THEGAME_HPP_
#define THEGAME_HPP_

#include "Player.hpp"
#include "Cat.hpp"
#include "EvilCat.hpp"
#include "Item.hpp"
#include "Weapon.hpp"
#include "CafeRobot.hpp"
#include "EvilRobot.hpp"
#include "Room.hpp"

#include "../cmd/cmd_help.hpp"
#include "../cmd/cmd_inventory.hpp"
#include "../cmd/cmd_stats.hpp"
#include "../cmd/cmd_equip_righthand.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>

using p_P = std::unique_ptr<Player>;
using p_F = std::unique_ptr<Fighter>;
using p_O = std::unique_ptr<Object>;
using p_R = std::shared_ptr<Room>;
using p_cmd = std::unique_ptr<cmd>;

class TheGame{
private:
	p_P Hero_;
	p_R currentRoom_;
	std::map<std::string, p_cmd > cmds_;

	void load_cmds();
	bool cmd_exist(std::string) const;
	std::string read_string() const;
//	int read_int() const;
	void take_command();
	//battle

public:
	TheGame(); //will create all the rooms, actors and items etc.
	virtual ~TheGame();
	void playTheGame();

};

#endif /* THEGAME_HPP_ */
