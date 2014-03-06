/*
 * cmd_inventory.hpp
 *
 *  Created on: 3 mar 2014
 *      Author: findus
 */

#ifndef CMD_INVENTORY_HPP_
#define CMD_INVENTORY_HPP_

#include "cmd.hpp"

using p_P = std::unique_ptr<Player>;
using p_R = std::shared_ptr<Room>;

class inventory: public cmd  {
public:
	inventory();
	virtual ~inventory();

	virtual std::pair< p_P, p_R > execute(p_P, p_R, std::string);
};

#endif /* CMD_INVENTORY_HPP_ */
