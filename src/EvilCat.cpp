/*
 * EvilCat.cpp
 *
 *  Created on: 11 feb 2014
 *      Author: findus
 */

#include "EvilCat.hpp"

EvilCat::EvilCat(std::string name):
Cat::Cat(name, 25, 2, 1){}

EvilCat::EvilCat(std::string name,int hp , int atk , int def):
Cat::Cat(name, hp, atk, def){}

EvilCat::~EvilCat(){}

std::string EvilCat::type() const{
	return "EvilCat";
}

int EvilCat::attack(){
	std::srand(time(NULL)); //generare different randomizations
	std::cout<<"Hit enter to let "<<this->name()<<" roll the dice! ";
	std::cin.ignore();
	int dice_toss = 1 + rand() % 6; //1 to 6
	std::cout<<"\nThe dice shows "<<dice_toss<<" points!"<<std::endl;
	int power = ATK_+dice_toss;
	return power;
}

std::unique_ptr<Inventory> EvilCat::talk(){
	std::cout<<"\nkekekekek! *_*"<<"\n"<<std::endl;
	return nullptr;
}

void EvilCat::stats() const{
	std::cout<<"Name: " << name() << "\nType: "<< type() <<"\nHP: "<< current_HP() <<"/"<< max_HP_<<std::endl;
}
