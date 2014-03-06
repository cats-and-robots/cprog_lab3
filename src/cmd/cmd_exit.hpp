/*
 * cmd_exit.hpp
 *
 *  Created on: 3 mar 2014
 *      Author: findus
 */

#ifndef CMD_EXIT_HPP_
#define CMD_EXIT_HPP_

#include "cmd.hpp"

using p_P = std::unique_ptr<Player>;
using p_R = std::shared_ptr<Room>;

class exit_room: public cmd {
public:
	exit_room();
	virtual ~exit_room();

	virtual std::pair< p_P, p_R > execute(p_P, p_R, std::string);
};

#endif /* CMD_EXIT_HPP_ */
