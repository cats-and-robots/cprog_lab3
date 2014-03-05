/*
 * cmd_equip_righthand.hpp
 *
 *  Created on: 3 mar 2014
 *      Author: findus
 */

#ifndef CMD_EQUIP_RIGHTHAND_HPP_
#define CMD_EQUIP_RIGHTHAND_HPP_

#include "cmd.hpp"

using p_P = std::unique_ptr<Player>;
using p_R = std::shared_ptr<Room>;
using p_O = std::unique_ptr<Object>;

class equip_righthand: public cmd {
public:
	equip_righthand();
	virtual ~equip_righthand();

	virtual std::pair< p_P, p_R > execute(p_P, p_R, std::string);
};

#endif /* CMD_EQUIP_RIGHTHAND_HPP_ */
