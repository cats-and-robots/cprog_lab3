/*
 * Fighter.hpp
 *
 *  Created on: 24 feb 2014
 *      Author: findus
 */

#ifndef FIGHTER_HPP_
#define FIGHTER_HPP_
#include <string>
#include "Inventory.hpp"
class Fighter {
protected:
	std::string name_;
	int current_HP_;
	int max_HP_;
	int ATK_;
	int DEF_;

public:
	std::unique_ptr<Inventory> inventory;
	virtual ~Fighter(){};
	virtual std::string type() const = 0;
	virtual std::string baseType() const = 0;
	virtual int attack() =0;
	virtual void talk() = 0;
	virtual void stats() const = 0;
	int current_HP() const{return current_HP_;}
	std::string name() const{return name_;}
	void takeDamage(int d){
		current_HP_-=d;
		if (current_HP_ < 0) current_HP_ = 0;
		if (current_HP_ > max_HP_) current_HP_ = max_HP_;
	}

};

#endif /* FIGHTER_HPP_ */
