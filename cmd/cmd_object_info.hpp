/*
 * cmd_object_info.hpp
 *
 *  Created on: 3 mar 2014
 *      Author: findus
 */

#ifndef CMD_OBJECT_INFO_HPP_
#define CMD_OBJECT_INFO_HPP_

#include "cmd.hpp"

using p_P = std::unique_ptr<Player>;
using p_R = std::shared_ptr<Room>;
using p_O = std::unique_ptr<Object>;

class object_info: public cmd {
public:
	object_info();
	virtual ~object_info();

	virtual std::pair< p_P, p_R > execute(p_P, p_R, std::string);
};

#endif /* CMD_OBJECT_INFO_HPP_ */
