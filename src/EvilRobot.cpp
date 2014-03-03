/*
 * EvilRobot.cpp
 *
 *  Created on: 11 feb 2014
 *      Author: findus
 */

#include "EvilRobot.hpp"


EvilRobot::EvilRobot(std::string name)
{
	name_ = name;
	current_HP_ = 1;
	max_HP_ = 1;
	DEF_ = 0;
	ATK_ = 0;
	std::unique_ptr<Inventory> inv(new Inventory);
	this->inventory = std::move(inv);
	loadQuizzes();
}

EvilRobot::EvilRobot(std::string name, int errors)
{
	name_ = name;
	current_HP_ = errors;
	max_HP_ = errors;
	DEF_ = 0;
	ATK_ = 0;
	std::unique_ptr<Inventory> inv(new Inventory);
	this->inventory = std::move(inv);
	loadQuizzes();
}



EvilRobot::~EvilRobot(){
	std::cout<<"Destroyed "<<this->type()<<" "<<this->name()<<std::endl;
}

std::string EvilRobot::type() const{
	return "EvilRobot";
}


int EvilRobot::attack(){
	//Show the question
	std::cout<<quizzes_[current_Quiz_index_]->question_<<std::endl;
	//show the alternatives
	for (unsigned int i = 0; i < quizzes_[current_Quiz_index_]->options_.size(); ++i){
		std::cout<<i+1<<": "<<quizzes_[current_Quiz_index_]->options_[i]<<std::endl;
	}

	//ask the user for the answer of the quiz
	int int_answer = 0;
	while (true) {
		std::cout << "Please enter a number between 1 and "<<quizzes_[current_Quiz_index_]->options_.size()<<std::endl;
		int_answer = this->read_int();
		if (int_answer > 0 && int_answer <= (int)quizzes_[current_Quiz_index_]->options_.size() )
			break;
		std::cout<<"Not a number between 1 and "<<quizzes_[current_Quiz_index_]->options_.size()<<std::endl;
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

void EvilRobot::talk(){
	std::cout<<"\n*BLIP-BLOP* Solve my quizzes!!! *BUZZ*"<<"\n\n";
}

void EvilRobot::stats() const{
	std::cout<<"Name: " << name() << "\nType: "<< type() <<"\nHP: "<< current_HP() <<"/"<< max_HP_<<std::endl;
}

int EvilRobot::read_int() const{
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

void EvilRobot::loadQuizzes(){
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
					newQuiz->answer_=answer;
					newQuiz->options_.push_back(answer);
				}
				else if (found_alt_pos!=std::string::npos){
					int start_substr = found_alt_pos+code_for_alt.length();
					std::string alt = line.substr(start_substr);
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
