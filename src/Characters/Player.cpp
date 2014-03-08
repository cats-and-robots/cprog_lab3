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
	DEF_=0;
	do_battle = false;
	std::unique_ptr<Inventory> inv(new Inventory);
	this->inventory = std::move(inv);
}

Player::~Player(){}

std::string Player::type() const{
	return "Player";
}

std::string Player::baseType() const{
	return "Fighter";
}

int Player::attack() {
	std::srand(time(NULL)); //generare different randomizations
	std::cout<<"Hit enter to roll the dice! ";
	std::cin.ignore();
	int dice_toss = 1 + rand() % 6; //1 to 6
	std::cout<<"\nThe dice shows "<<dice_toss<<( (dice_toss == 1) ? " point!" : " points!" )<<std::endl;
	int power = this->get_attack_stat() + dice_toss;
	if (RH_) power+= RH_->getATK();
	if (LH_) power+= LH_->getATK();
	return power;
}

int Player::defense() const{
	int def = this->get_defense_stat();
	if (RH_) def+= RH_->getDEF();
	if (LH_) def+= LH_->getDEF();
	return def;
}

std::unique_ptr<Inventory> Player::talk(){
	std::cout<<"\nI am "<<name()<<"!\n\n";
	return nullptr;
}

void Player::stats() const{

	std::cout<<this->type()<<" "<<this->name()<<std::endl;
	std::cout<<"HP: "<<current_HP_<<"/"<<max_HP_<<std::endl;
	std::cout<<"ATK: "<<this->get_attack_stat() + ( (RH_ != NULL) ? RH_->getATK() : 0 )  + ( (LH_ != NULL) ? LH_->getATK() : 0 ) <<std::endl;
	std::cout<<"DEF: "<<this->get_defense_stat() + ( (RH_ != NULL) ? RH_->getDEF() : 0 )  + ( (LH_ != NULL) ? LH_->getDEF() : 0 ) <<std::endl;
	std::cout<<"Right hand: " << ( (RH_ != NULL) ? RH_->name() : "-" )<<std::endl;
	std::cout<<"Left hand: "  << ( (LH_ != NULL) ? LH_->name() : "-" )<<std::endl;
}

bool Player::isEquipped_RH() const{
	if (this->RH_) return true;
	else return false;
}
bool Player::isEquipped_LH() const{
	if (this->LH_) return true;
	else return false;
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

//std::unique_ptr<Fighter> Player::fight(std::unique_ptr<Fighter> actor){
void Player::fight(std::unique_ptr<Character>& actor){
	if (actor->type() == "EvilRobot"){
		int quiz_result = actor->attack();
		/* For different values from calling attack()
		 * 0 = you gave a correct answer and inflicted damage on the robot!
		 * 1 = you gave an incorrect answer and will lose half of your max_HP
		 * -1 = you gave an incorrect answer and will lose all you HP
		 * */
		if (quiz_result == 0){
			std::cout<<this->name() <<" inflicted " << actor->name() <<" with 1 malfunction!"<<std::endl;
			actor->takeDamage(1);
		}
		else if (quiz_result == 1){
			int half_max_HP = (int)ceil( (float)max_HP_ / 2 );
			std::cout<<actor->name() <<" inflicted " << this->name() <<" with "<< half_max_HP <<" damage-points!"<<std::endl;
			this->takeDamage(half_max_HP);
		}
		else if (quiz_result == -1){
			std::cout<<actor->name() <<" inflicted " << this->name() <<" with "<< max_HP_ <<" damage-points!"<<std::endl;
			this->takeDamage(max_HP_);
		}
		std::cout<<"Current HP: "<<this->current_HP()<<"/"<<this->max_HP_<<std::endl;
		std::cout<<"Hit enter to continue";
		std::cin.ignore();
	}
	//For all other creatures that you will fight
	else{
		std::srand(time(NULL));
		int random_start = rand() % 2; //0 or 1
		int damage;
		if (random_start == 1){
			std::cout<< this->name() <<" attacks "<< actor->name() <<" first!" <<std::endl;
			damage = this->attack() - actor->defense();
			actor->takeDamage(damage);
			std::cout<< this->name() <<" inflicted "<< actor->name() <<
					" with "<< damage << " damage-points!" <<std::endl;
			if (actor->current_HP() > 0){
				damage = actor->attack() - this->defense();
				this->takeDamage(damage);
				std::cout<< actor->name() <<" inflicted "<< this->name() <<
						" with "<< damage << " damage-points!" <<std::endl;
			}
		}
		else if (random_start == 0){
			std::cout<<actor->name() <<" attacks first!" <<std::endl;
			damage = actor->attack() - this->defense();
			this->takeDamage(damage);
			std::cout<< actor->name() <<" inflicted "<< this->name() <<
					" with "<< damage << " damage-points!" <<std::endl;
			if (this->current_HP() > 0){
				damage = this->attack() - actor->defense();
				actor->takeDamage(damage);
				std::cout<< this->name() <<" inflicted "<< actor->name() <<
						" with "<< damage << " damage-points!" <<std::endl;
			}
		}
		std::cout<<"\nCurrent HP: "<<this->current_HP()<<"/"<<this->max_HP_<<"\n"<<std::endl;
	}


}

