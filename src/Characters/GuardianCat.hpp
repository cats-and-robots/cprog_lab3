/*
 * GuardianCat.hpp
 *
 *  Created on: 5 mar 2014
 *      Author: findus
 */

#ifndef GuardianCat_HPP_
#define GuardianCat_HPP_

#include <iostream>
#include <string>
#include <fstream> //for file reading
#include "Cat.hpp"

class GuardianCat: public Cat {
private:
	std::string use_code_;
	bool entrance_;

public:
	explicit GuardianCat(std::string,std::string);
	virtual ~GuardianCat();

	virtual std::string type() const;
	virtual std::unique_ptr<Inventory> talk();
	virtual bool use(std::string);
};

#endif /* GuardianCat_HPP_ */
