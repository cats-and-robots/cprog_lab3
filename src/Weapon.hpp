/*
 * Weapon.hpp
 *
 *  Created on: 13 feb 2014
 *      Author: findus
 */

#ifndef WEAPON_HPP_
#define WEAPON_HPP_

#include "Item.hpp"

class Weapon:public Item {
private:
	int ATK_;
	int DEF_;
public:
	Weapon();
	explicit Weapon(std::string,std::string,int,int);
	virtual ~Weapon();

	virtual std::string type() const;
	virtual int getATK() const;
	virtual int getDEF() const;

	friend std::ostream& operator<<(std::ostream&, const Object&);
};

#endif /* WEAPON_HPP_ */
