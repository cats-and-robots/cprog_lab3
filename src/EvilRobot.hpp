/*
 * EvilRobot.hpp
 *
 *  Created on: 11 feb 2014
 *      Author: findus
 */

#ifndef EVILROBOT_HPP_
#define EVILROBOT_HPP_



#include "Robot.hpp"
#include <vector>
#include <memory> //smart pointers
#include <algorithm> //for shuffle
#include <fstream> //for file reading
#include <sstream> //for stringsstream

static const unsigned int MAX = 4; //number of quiz-files in the EvilRobot folder

struct Quiz{
	std::string question_;
	std::string answer_;
	std::vector<std::string> options_;

};

class EvilRobot:public Robot {

private:
	std::vector< std::unique_ptr<Quiz> > quizzes_;
	int current_Quiz_index_ = 0;
	int read_int() const;
	void loadQuizzes();

public:
	explicit EvilRobot(std::string);
	explicit EvilRobot(std::string, int);
	virtual ~EvilRobot();

	virtual std::string type() const;
	virtual int attack();
	virtual std::unique_ptr<Inventory> talk();
	virtual void stats() const;

};

#endif /* EVILROBOT_HPP_ */
