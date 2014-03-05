/*
 * EvilCat.cpp
 *
 *  Created on: 11 feb 2014
 *      Author: findus
 */

#include "EvilCat.hpp"

EvilCat::EvilCat(std::string name):
Cat::Cat(name, 25, 1, 2){}

EvilCat::EvilCat(std::string name,int hp , int def , int atk):
Cat::Cat(name, hp, def, atk){}

EvilCat::~EvilCat() {std::cout<<"Destroyed "<<type()<<" "<<name()<<std::endl;}

std::string EvilCat::type() const{
	return "EvilCat";
}

int EvilCat::attack(){
	std::srand(time(NULL)); //generare different randomizations
	std::cout<<"Hit enter to let "<<this->name()<<" roll the dice! ";
	char tmp;
	tmp = std::cin.get();
	int dice_toss = 1 + rand() % 6; //1 to 6
	std::cout<<"The dice shows "<<dice_toss<<" points!"<<std::endl;
	int power = ATK_+dice_toss;
	return power;
}

std::unique_ptr<Inventory> EvilCat::talk(){
	std::cout<<"\nkekekekek! *_*"<<"\n\n";
	return nullptr;
}

void EvilCat::stats() const{
	std::cout<<"Name: " << name() << "\nType: "<< type() <<"\nHP: "<< current_HP() <<"/"<< max_HP_<<std::endl;
}
