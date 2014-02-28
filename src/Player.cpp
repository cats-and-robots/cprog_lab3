/*
 * Player.cpp
 *
 *  Created on: 24 feb 2014
 *      Author: findus
 */

#include "Player.hpp"

Player::Player(std::string name){
	name_=name;
	current_HP_=100;
	max_HP_=100;
	ATK_=5;
	DEF_=20;
	std::cout<<"Created "<<this->type()<<" "<<this->name()<<std::endl;
}

Player::~Player() {
	std::cout<<"Destroyed "<<this->type()<<" "<<this->name()<<std::endl;
}

int Player::attack() {
	int power = ATK_;
	if (RH_) power+= RH_->getATK();
	if (LH_) power+= LH_->getATK();
	return power;
}

void Player::talk(){
	std::cout<<"\nI am "<<name()<<"!\n\n";
}

void Player::stats() const{
	std::cout<<this->type()<<" "<<this->name()<<std::endl;
	std::cout<<"HP: "<<current_HP_<<"/"<<max_HP_<<std::endl;
	std::cout<<"ATK: "<<ATK_<<std::endl;
	std::cout<<"DEF: "<<DEF_<<std::endl;
	std::cout<<"Right hand: ";
	if (RH_) std::cout<<RH_->name()<<std::endl;
	else std::cout<<"-"<<std::endl;
	std::cout<<"Left hand: ";
	if (LH_) std::cout<<LH_->name()<<std::endl;
	else std::cout<<"-"<<std::endl;
}

void Player::equip_RH(std::unique_ptr<Object> r_wep){
	RH_ = std::move(r_wep);
}
void Player::equip_LH(std::unique_ptr<Object> l_wep){
	LH_ = std::move(l_wep);
}
std::unique_ptr<Object> Player::unequip_RH(){
	return std::move(RH_);
}
std::unique_ptr<Object> Player::unequip_LH(){
	return std::move(LH_);
}
//void fight(std::vector< std::unique_ptr<Animal> > animals, std::vector< std::unique_ptr<Robot> > robots ){
//	if (animals && robots){
//
//	}
//
//}

