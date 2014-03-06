/*
 * Potion.hpp
 *
 *  Created on: 3 mar 2014
 *      Author: findus
 */

#ifndef POTION_HPP_
#define POTION_HPP_

#include "Item.hpp"
//#include "Object.hpp"

class Potion:public Item {
//class Potion: public Object {
public:
//	Potion();
	explicit Potion(std::string,std::string,int);
	virtual ~Potion();

	virtual int getATK() const;
	virtual int getDEF() const;
	virtual std::string type() const;
};

#endif /* POTION_HPP_ */
