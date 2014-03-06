/*
 * cmd.hpp
 *
 *  Created on: 2 mar 2014
 *      Author: findus
 */

#ifndef CMD_HPP_
#define CMD_HPP_

#include <iostream>
#include <string>
#include <utility> //for std::pair
#include <memory> //for smart pointer
#include "./../Characters/Player.hpp"
#include "./../Room/Room.hpp"

using p_P = std::unique_ptr<Player>;
using p_R = std::shared_ptr<Room>;

class cmd{
public:
	virtual ~cmd(){};
	virtual std::pair< p_P, p_R > execute(p_P, p_R, std::string) = 0;
protected:
	int read_int() const{
		std::string input = "";
		int int_input = 0;
		while (true){
			std::cout<<">> ";
			std::getline(std::cin, input);
			std::stringstream myStream(input);
			if (myStream >> int_input)
				break;
			std::cout << "Not an integer, please try again!" << std::endl;
		}
		return int_input;
	}

};


#endif /* CMD_HPP_ */
