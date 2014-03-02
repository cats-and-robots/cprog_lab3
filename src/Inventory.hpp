/*
 * Inventory.hpp
 *
 *  Created on: 19 feb 2014
 *      Author: findus
 */

#ifndef INVENTORY_HPP_
#define INVENTORY_HPP_
#include <map> //for map
#include <memory> //for smart pointers
#include <vector>
#include "Item.hpp"
#include "Weapon.hpp"

class Inventory {

protected:
	std::map<std::string, std::unique_ptr<Object> > items_;

public:
	Inventory();
	virtual ~Inventory();

	void put(std::unique_ptr<Object> );
	std::unique_ptr<Object> take(std::string);
	void show_inventory() const;
	std::vector< std::unique_ptr<Object> >  loot();

};

#endif /* INVENTORY_HPP_ */
