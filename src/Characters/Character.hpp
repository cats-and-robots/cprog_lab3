/*
 * Character.hpp
 *
 *  Created on: 24 feb 2014
 *      Author: findus
 */

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_
#include <string>
#include <memory> //smart pointers
#include "./../Inventory/Inventory.hpp"
class Character {
protected:
	std::string name_;
	int current_HP_;
	int max_HP_;
	int ATK_;
	int DEF_;

public:
	std::unique_ptr<Inventory> inventory;
	virtual ~Character(){};
	virtual std::string type() const = 0;
	virtual std::string baseType() const = 0;
	virtual int attack() =0;
	virtual int get_attack_stat() const{return ATK_;}
	virtual int get_defense_stat() const{return DEF_;}
	virtual int defense() const{return DEF_;}
	virtual std::unique_ptr<Inventory> talk() = 0;
	virtual void stats() const = 0;
	virtual bool use(std::string){return false;}
	virtual void full_restore(){current_HP_ = max_HP_;}
	int current_HP() const{return current_HP_;}
	std::string name() const{return name_;}
	void change_name(std::string name){name_=name;}
	void takeDamage(int d){
		current_HP_-=d;
		if (current_HP_ < 0) current_HP_ = 0;
		if (current_HP_ > max_HP_) current_HP_ = max_HP_;
	}
	bool isDead() const{return current_HP_ <= 0;}

};

#endif /* CHARACTER_HPP_ */
