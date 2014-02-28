/*
 * Player.hpp
 *
 *  Created on: 24 feb 2014
 *      Author: findus
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_
#include <map>
#include <memory>
#include "Fighter.hpp"
#include "Inventory.hpp"
class Player: public Fighter, public Inventory{
private:
	std::unique_ptr<Object> RH_;
	std::unique_ptr<Object> LH_;
public:
	explicit Player(std::string);
	virtual ~Player();
	virtual std::string type() const;
	virtual std::string baseType() const;
	virtual int attack();
	virtual void talk();
	void stats() const;
	void equip_RH(std::unique_ptr<Object>);
	void equip_LH(std::unique_ptr<Object>);
	std::unique_ptr<Object> unequip_RH();
	std::unique_ptr<Object> unequip_LH();
	//void fight(std::vector< std::unique_ptr<Animal> >, std::vector< std::unique_ptr<Robot> >  );

	friend std::ostream& operator<<(std::ostream& stream, const Player& x){
		stream <<"Name: " << x.name() << "\nType: "<< x.type() <<"\nHP: "
				<< x.current_HP() <<"/"<<x.max_HP_;
		return stream;
	}
};

#endif /* PLAYER_HPP_ */
