/*
 * EvilCat.hpp
 *
 *  Created on: 11 feb 2014
 *      Author: findus
 */

#ifndef EVILCAT_HPP_
#define EVILCAT_HPP_

#include "Cat.hpp"

class EvilCat: public Cat {

public:
	explicit EvilCat(std::string);
	explicit EvilCat(std::string, int, int, int);
	virtual ~EvilCat();

	virtual std::string type() const;
	virtual int attack();
	virtual void talk();
	virtual void stats() const;

};

#endif /* EVILCAT_HPP_ */
