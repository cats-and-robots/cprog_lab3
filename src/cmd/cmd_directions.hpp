/*
 * cmd_directions.hpp
 *
 *  Created on: 3 mar 2014
 *      Author: findus
 */

#ifndef CMD_DIRECTIONS_HPP_
#define CMD_DIRECTIONS_HPP_

#include "cmd.hpp"

using p_P = std::unique_ptr<Player>;
using p_R = std::shared_ptr<Room>;

class directions: public cmd {
public:
	directions();
	virtual ~directions();

	virtual std::pair< p_P, p_R > execute(p_P, p_R, std::string);
};

#endif /* CMD_DIRECTIONS_HPP_ */
