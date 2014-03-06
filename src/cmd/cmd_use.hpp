/*
 * cmd_use.hpp
 *
 *  Created on: 3 mar 2014
 *      Author: findus
 */

#ifndef CMD_USE_HPP_
#define CMD_USE_HPP_

#include "cmd.hpp"

using p_P = std::unique_ptr<Player>;
using p_R = std::shared_ptr<Room>;
using p_O = std::unique_ptr<Object>;


class use_object: public cmd {
public:
	use_object();
	virtual ~use_object();

	virtual std::pair< p_P, p_R > execute(p_P, p_R, std::string);
};

#endif /* CMD_USE_HPP_ */
