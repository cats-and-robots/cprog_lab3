/*
 * Fighter.hpp
 *
 *  Created on: 24 feb 2014
 *      Author: findus
 */

#ifndef FIGHTER_HPP_
#define FIGHTER_HPP_
#include <string>
class Fighter {
protected:
	std::string name_;
	int current_HP_;
	int max_HP_;
	int ATK_;
	int DEF_;

public:
	virtual ~Fighter(){};
	virtual std::string type() const = 0;
	virtual std::string baseType() const = 0;
	virtual int attack() =0;
	virtual void talk() = 0;
	int current_HP() const{return current_HP_;}
	void takeDamage(int d){current_HP_-=d;}
	std::string name() const{return name_;}

};

#endif /* FIGHTER_HPP_ */
