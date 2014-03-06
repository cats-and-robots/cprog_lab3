/*
 * cmd_go_to.hpp
 *
 *  Created on: 3 mar 2014
 *      Author: findus
 */

#ifndef CMD_GO_TO_HPP_
#define CMD_GO_TO_HPP_

#include "cmd.hpp"

using p_P = std::unique_ptr<Player>;
using p_R = std::shared_ptr<Room>;

class go_to: public cmd {
public:
	go_to();
	virtual ~go_to();

	virtual std::pair< p_P, p_R > execute(p_P, p_R, std::string);
};

#endif /* CMD_GO_TO_HPP_ */
