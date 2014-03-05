/*
 * cmd_help.hpp
 *
 *  Created on: 2 mar 2014
 *      Author: findus
 */

#ifndef HELP_HPP_
#define HELP_HPP_

#include "cmd.hpp"
#include "iomanip"

using p_P = std::unique_ptr<Player>;
using p_R = std::shared_ptr<Room>;

class help: public cmd {
public:
	help();
	virtual ~help();

	virtual std::pair< p_P, p_R > execute(p_P, p_R, std::string);
};

#endif /* HELP_HPP_ */
