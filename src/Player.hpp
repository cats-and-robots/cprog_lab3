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
#include "Fighter.hpp"
#include "EvilCat.hpp"
#include "EvilRobot.hpp"
#include "CafeRobot.hpp"
#include "Inventory.hpp"

class Player: public Fighter{
private:
	std::unique_ptr<Object> RH_;
	std::unique_ptr<Object> LH_;
public:
	explicit Player(std::string);
	virtual ~Player();
	virtual std::string type() const;
	virtual std::string baseType() const;
	virtual int attack();
	virtual void talk();
	virtual void stats() const;
	bool isEquipped_RH() const;
	bool isEquipped_LH() const;
	void equip_RH(std::unique_ptr<Object>);
	void equip_LH(std::unique_ptr<Object>);
	std::unique_ptr<Object> unequip_RH();
	std::unique_ptr<Object> unequip_LH();
	std::unique_ptr<Fighter> fight(std::unique_ptr<Fighter> );

};

#endif /* PLAYER_HPP_ */
