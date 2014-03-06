/*
 * TheGame.hpp
 *
 *  Created on: 1 mar 2014
 *      Author: findus
 */

#ifndef THEGAME_HPP_
#define THEGAME_HPP_

#include "Player.hpp"
#include "EvilCat.hpp"
#include "GuardianCat.hpp"
#include "CafeRobot.hpp"
#include "EvilRobot.hpp"
#include "Room.hpp"

#include "../cmd/cmd_help.hpp"
#include "../cmd/cmd_inventory.hpp"
#include "../cmd/cmd_stats.hpp"
#include "../cmd/cmd_equip_righthand.hpp"
#include "../cmd/cmd_equip_lefthand.hpp"
#include "../cmd/cmd_unequip_righthand.hpp"
#include "../cmd/cmd_unequip_lefthand.hpp"
#include "../cmd/cmd_look_around.hpp"
#include "../cmd/cmd_directions.hpp"
#include "../cmd/cmd_take.hpp"
#include "../cmd/cmd_talk_to.hpp"
#include "../cmd/cmd_go_to.hpp"
#include "../cmd/cmd_exit.hpp"
#include "../cmd/cmd_use.hpp"
#include "../cmd/cmd_object_info.hpp"



#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <utility> 		//std::pair
#include <sstream> 		//stringstream


using p_P = std::unique_ptr<Player>;
using p_F = std::unique_ptr<Fighter>;
using p_O = std::unique_ptr<Object>;
using p_R = std::shared_ptr<Room>;
using p_cmd = std::unique_ptr<cmd>;

class TheGame{
private:
	p_P Hero_;
	p_R current_room_;
	std::map<std::string, p_cmd > cmds_;
	std::map<std::string, p_R> all_rooms_;
	bool continue_game_;
	bool special_event_1_has_happened_;
	bool special_event_2_has_happened_;
	bool cleared_stage_1_;
	bool cleared_stage_2_;
	bool played_before_;

	void load_cmds();
	bool cmd_exist(std::string) const;
	std::string read_string() const;
	int read_int() const;
	void lex_analys(const std::string&, std::string&, std::string&) const;
	void take_command();
	void battle();
	void put_room(p_R);
	p_R take_room(std::string);

	void intro() const;
	void credits() const;
	void set_hero_name();
	void stage_1();
	void stage_2();
	void stage_cat_cafe();
	void playTheGame();

	void create_new_game();


public:
	TheGame(); //will create all the rooms, actors and items etc.
	virtual ~TheGame();
	void meny();

};

#endif /* THEGAME_HPP_ */
