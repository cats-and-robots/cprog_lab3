/*
 * Cat.hpp
 *
 *  Created on: 11 feb 2014
 *      Author: findus
 */

#ifndef CAT_HPP_
#define CAT_HPP_

#include "Animal.hpp"

class Cat: public Animal {

public:
	explicit Cat(std::string);
	explicit Cat(std::string, int,int,int);
	virtual ~Cat();

	virtual std::string type() const;
	virtual void talk();

	friend std::ostream& operator<<(std::ostream&, const Animal&);
};

#endif /* CAT_HPP_ */
