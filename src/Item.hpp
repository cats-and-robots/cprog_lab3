/*
 * Item.h
 *
 *  Created on: 7 feb 2014
 *      Author: findus
 */

#ifndef ITEM_HPP_
#define ITEM_HPP_

#include "Object.hpp"

class Item: public Object{
public:

	Item();
	explicit Item(std::string,std::string);
	virtual ~Item();

	virtual int getATK() const;
	virtual int getDEF() const;
	virtual std::string type() const;

	friend std::ostream& operator<<(std::ostream&, const Object&);
};


#endif /* ITEM_HPP_ */
