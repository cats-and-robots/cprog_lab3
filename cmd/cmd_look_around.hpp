/*
 * cmd_look_around.hpp
 *
 *  Created on: 3 mar 2014
 *      Author: findus
 */

#ifndef CMD_LOOK_AROUND_HPP_
#define CMD_LOOK_AROUND_HPP_

#include "cmd.hpp"

using p_P = std::unique_ptr<Player>;
using p_R = std::shared_ptr<Room>;

class look_around: public cmd {
public:
	look_around();
	virtual ~look_around();

	virtual std::pair< p_P, p_R > execute(p_P, p_R, std::string);
};

#endif /* CMD_LOOK_AROUND_HPP_ */
