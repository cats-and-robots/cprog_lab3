/*
 * EvilRobot.hpp
 *
 *  Created on: 11 feb 2014
 *      Author: findus
 */

#ifndef EVILROBOT_HPP_
#define EVILROBOT_HPP_



#include "Robot.hpp"
#include "Weapon.hpp" //contains Item.hpp
#include <memory>
#include <fstream> //for file reading
class EvilRobot:public Robot {

protected:

	std::unique_ptr<Object> item_;
	void set_QuizFile(std::string file){
		std::cout<<"setQuizFile got file: "<<file<<std::endl;
	}

public:

	explicit EvilRobot(std::string name)
	{
		name_ = name;
		current_HP_ = 1;
		max_HP_ = 1;
		DEF_ = 0;
		ATK_ = 0;
	}

	explicit EvilRobot(std::string name, int errors)
	{
		name_ = name;
		current_HP_ = errors;
		max_HP_ = errors;
		DEF_ = 0;
		ATK_ = 0;
	}

	explicit EvilRobot(std::string name, std::unique_ptr<Object> item):
		item_(std::move(item))
	{
		name_ = name;
		current_HP_ = 1;
		max_HP_ = 1;
		DEF_ = 0;
		ATK_ = 0;
	}

	explicit EvilRobot(std::string name, int errors, std::unique_ptr<Object> item):
		item_(std::move(item))
	{
		name_ = name;
		current_HP_ = errors;
		max_HP_ = errors;
		DEF_ = 0;
		ATK_ = 0;

	}

	virtual ~EvilRobot(){
		std::cout<<"Destroyed "<<this->type()<<" "<<this->name()<<std::endl;
	}

	virtual std::string type() const{
		return "EvilRobot";
	}

	virtual int attack() const{

		//Generating an integer between 1 to max
		int max = 4;
		std::srand(time(NULL));
		int nr = 1 + ( std::rand() % max );


		//open and read file corresponding to the generated integer
		std::string filename = "EvilRobotQuiz/"+std::to_string(nr)+".txt";
		std::ifstream quizfile(filename);
		std::string line;

		if (quizfile.is_open()){
			while ( std::getline (quizfile,line) ){
				std::cout << line <<std::endl;
		    }
			quizfile.close();
		}
		else
			std::cout << "Unable to open file ./" << filename <<std::endl;


		return 1;
	}

	virtual void talk() const{
		std::cout<<"\n*BLIP-BLOP* Solve my quizzes!!! *BUZZ*"<<"\n";
	}

	std::unique_ptr<Object> getItem(){
		return std::move(item_);
	}

	friend std::ostream& operator<<(std::ostream& stream, const EvilRobot& x){
		//std::string item_type = typeid(x.ITEM).name();
		stream <<"Name: " << x.name() << "\nType: " << x.type()
				<<"\nErrors: "<<x.current_HP_<<"\n";
				//(ITEM != 0) ? *(x.ITEM) : "Empty";
		return stream;
	}


};

#endif /* EVILROBOT_HPP_ */
