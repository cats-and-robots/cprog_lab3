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
#include <vector>
#include <memory>
#include <algorithm> //for shuffle
#include <fstream> //for file reading
#include <sstream> //for stringsstream

const unsigned int MAX = 4; //number of quiz-files in the EvilRobot folder

struct Quiz{
	std::string question_;
	std::string answer_;
	std::vector<std::string> options_;
};

class EvilRobot:public Robot {

protected:

	std::vector< std::unique_ptr<Quiz> > quizzes_;
	std::unique_ptr<Object> item_;
	int current_Quiz_index_ = 0;


	void loadQuizzes(){

		std::srand(time(NULL)); //generare different randomizations


		std::string code_for_answer = "#ANSWER:";
		std::string code_for_alt = "#ALT:";
		std::string line;

		for (unsigned int nr = 1; nr<MAX+1; ++nr ){
			//open and read file corresponding to the generated integer
			std::string filename = "EvilRobotQuiz/"+std::to_string(nr)+".txt";
			std::ifstream quizfile(filename);

			if (quizfile.is_open()){
				std::unique_ptr<Quiz> newQuiz(new Quiz());
				while ( std::getline (quizfile,line) ){
					std::size_t found_ans_pos = line.find(code_for_answer);
					std::size_t found_alt_pos = line.find(code_for_alt);
					if (found_ans_pos!=std::string::npos){
						int start_substr = found_ans_pos+code_for_answer.length();
						std::string answer = line.substr(start_substr);
						//std::cout<<"Answer:"<<answer<<"."<<std::endl;
						newQuiz->answer_=answer;
						newQuiz->options_.push_back(answer);
					}
					else if (found_alt_pos!=std::string::npos){
						int start_substr = found_alt_pos+code_for_alt.length();
						std::string alt = line.substr(start_substr);
						//std::cout<<"Alt:"<<alt<<"."<<std::endl;
						newQuiz->options_.push_back(alt);
					}
					else{
						newQuiz->question_ += line + '\n';
					}

			    }

				//shuffle options before saving
				std::random_shuffle( newQuiz->options_.begin(), newQuiz->options_.end() );
				quizzes_.push_back(std::move(newQuiz));
				quizfile.close();
			}
			else
				std::cout << "Unable to open file ./" << filename <<std::endl;


		}
		//shuffle quizzes
		std::random_shuffle( quizzes_.begin(), quizzes_.end() );

//		for (unsigned int i=0; i<quizzes_.size(); ++i){
//			std::cout<<quizzes_[i]->question_<<std::endl;
//			std::cout<<quizzes_[i]->answer_<<std::endl;
//			for (unsigned int j=0; j<quizzes_[i]->options_.size(); ++j){
//				std::cout<<quizzes_[i]->options_[j]<<std::endl;
//			}
//		}


	}

public:

	explicit EvilRobot(std::string name)
	{
		name_ = name;
		current_HP_ = 1;
		max_HP_ = 1;
		DEF_ = 0;
		ATK_ = 0;
		loadQuizzes();
	}

	explicit EvilRobot(std::string name, int errors)
	{
		name_ = name;
		current_HP_ = errors;
		max_HP_ = errors;
		DEF_ = 0;
		ATK_ = 0;
		loadQuizzes();
	}

	explicit EvilRobot(std::string name, std::unique_ptr<Object> item):
		item_(std::move(item))
	{
		name_ = name;
		current_HP_ = 1;
		max_HP_ = 1;
		DEF_ = 0;
		ATK_ = 0;
		loadQuizzes();
	}

	explicit EvilRobot(std::string name, int errors, std::unique_ptr<Object> item):
		item_(std::move(item))
	{
		name_ = name;
		current_HP_ = errors;
		max_HP_ = errors;
		DEF_ = 0;
		ATK_ = 0;
		loadQuizzes();
	}

	virtual ~EvilRobot(){
		std::cout<<"Destroyed "<<this->type()<<" "<<this->name()<<std::endl;
	}

	virtual std::string type() const{
		return "EvilRobot";
	}

	virtual int attack(){
		//Show the question
		std::cout<<quizzes_[current_Quiz_index_]->question_<<std::endl;
		//show the alternatives
		for (unsigned int i = 0; i < quizzes_[current_Quiz_index_]->options_.size(); ++i){
			std::cout<<i+1<<": "<<quizzes_[current_Quiz_index_]->options_[i]<<std::endl;
		}

		//get input, and convert it to an integer
		unsigned int int_answer = 0;
		std::string input = "";
		while (true) {
			std::cout << "Please enter a number between 1 and "<<quizzes_[current_Quiz_index_]->options_.size()<<".\n>> ";
			std::getline(std::cin, input);

			// This code converts from string to number safely.
			std::stringstream myStream(input);
			if (myStream >> int_answer && int_answer > 0 && int_answer <= quizzes_[current_Quiz_index_]->options_.size() )
				break;
			std::cout << "Invalid number, please try again!" << std::endl;
		}

		int return_value;
		std::string str_answer = quizzes_[current_Quiz_index_]->options_[int_answer-1];
		if (quizzes_[current_Quiz_index_]->answer_.compare(str_answer) == 0 ){
			std::cout<<"Correct!"<<std::endl;
			return_value = 0;
		}
		else{
			std::cout<<"Incorrect!"<<std::endl;
			if (quizzes_[current_Quiz_index_]->options_.size() == 2) //instant death!
				return_value = -1;
			else //lose half of current health points
				return_value = 1;
		}

		++current_Quiz_index_;
		//if we have gone through all quizzes, reset the Quiz-index and shuffle the order of the quizzes
		if (current_Quiz_index_ == MAX){
			current_Quiz_index_ = 0;
			std::random_shuffle( quizzes_.begin(), quizzes_.end() );
		}
		return return_value;
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
