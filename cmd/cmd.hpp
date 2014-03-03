/*
 * cmd.hpp
 *
 *  Created on: 2 mar 2014
 *      Author: findus
 */

#ifndef CMD_HPP_
#define CMD_HPP_

#include <iostream>
#include <string>
#include <utility> //for std::pair
#include <memory> //for smart pointer
#include "../src/Player.hpp"
#include "../src/Room.hpp"

using up_P = std::unique_ptr<Player>;
using sp_R = std::shared_ptr<Room>;

class cmd{
public:

	virtual ~cmd(){};
	virtual std::pair< up_P, sp_R > execute(up_P, sp_R, std::string) = 0;
};


#endif /* CMD_HPP_ */
