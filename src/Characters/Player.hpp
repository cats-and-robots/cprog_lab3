/*
 * Player.hpp
 *
 *  Created on: 24 feb 2014
 *      Author: findus
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_
#include <map>
#include <memory> //for smart pointers
#include "Character.hpp"
#include "EvilCat.hpp"
#include "EvilRobot.hpp"
#include "CafeRobot.hpp"
#include "./../Inventory/Inventory.hpp"

class Player: public Character{
private:
	std::unique_ptr<Object> RH_;
	std::unique_ptr<Object> LH_;
public:
	explicit Player(std::string);
	virtual ~Player();
	bool do_battle;
	virtual std::string type() const;
	virtual std::string baseType() const;
	virtual int attack();
	virtual std::unique_ptr<Inventory> talk();
	virtual void stats() const;
	bool isEquipped_RH() const;
	bool isEquipped_LH() const;
	void equip_RH(std::unique_ptr<Object>);
	void equip_LH(std::unique_ptr<Object>);
	std::unique_ptr<Object> unequip_RH();
	std::unique_ptr<Object> unequip_LH();
//	std::unique_ptr<Fighter> fight(std::unique_ptr<Fighter> );
	void fight(std::unique_ptr<Character> & );

};

#endif /* PLAYER_HPP_ */
