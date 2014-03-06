/*
 * cmd_stats.hpp
 *
 *  Created on: 3 mar 2014
 *      Author: findus
 */

#ifndef CMD_STATS_HPP_
#define CMD_STATS_HPP_

#include "cmd.hpp"

using p_P = std::unique_ptr<Player>;
using p_R = std::shared_ptr<Room>;

class stats: public cmd {
public:
	stats();
	virtual ~stats();

	virtual std::pair< p_P, p_R > execute(p_P, p_R, std::string);
};

#endif /* CMD_STATS_HPP_ */
