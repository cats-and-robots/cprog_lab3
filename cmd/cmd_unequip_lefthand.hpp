/*
 * cmd_unequip_lefthand.hpp
 *
 *  Created on: 3 mar 2014
 *      Author: findus
 */

#ifndef CMD_UNEQUIP_LEFTHAND_HPP_
#define CMD_UNEQUIP_LEFTHAND_HPP_

#include "cmd.hpp"

using p_P = std::unique_ptr<Player>;
using p_R = std::shared_ptr<Room>;
using p_O = std::unique_ptr<Object>;

class unequip_lefthand: public cmd {
public:
	unequip_lefthand();
	virtual ~unequip_lefthand();

	virtual std::pair< p_P, p_R > execute(p_P, p_R, std::string);
};

#endif /* CMD_UNEQUIP_LEFTHAND_HPP_ */
