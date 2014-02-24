/*
 * Inventory.hpp
 *
 *  Created on: 19 feb 2014
 *      Author: findus
 */

#ifndef INVENTORY_HPP_
#define INVENTORY_HPP_
#include <map> //for map
#include "Item.hpp"
#include "Weapon.hpp"
#include <memory>

class Inventory {

protected:

	std::map<std::string, std::unique_ptr<Object> > items_;

public:

	Inventory(){std::cout<<"Created a Inventory!"<<std::endl;};
	virtual ~Inventory(){std::cout<<"Destroyed a Inventory!"<<std::endl;}

	void put(std::unique_ptr<Object> item){
		std::cout<<"Inserted "<<item->type() <<" "<<item->name()<<"!"<<std::endl;
		items_.insert (std::pair< std::string, std::unique_ptr<Object> >
			(item->name(),std::move(item)) );
	}

	std::unique_ptr<Object> take(std::string name){
		for (auto iter = items_.find(name); iter != items_.end(); ++iter){
			if (iter->first == name){
				std::unique_ptr<Object> thing = std::move(iter->second);
				items_.erase(iter);
				return std::move(thing);
			}
		}
		return nullptr;
	}

	void show_inventory() const{
		int counter = 1;
		if (items_.size()>0 ){
			if (items_.size() == 1 )
				std::cout<<"One object:"<<std::endl;
			else
				std::cout<<"Several objects:"<<std::endl;
			for (auto iter = items_.begin(); iter != items_.end(); ++iter){
				std::cout<< counter++ <<": "<< iter->second->type()<< " " <<iter->first<<std::endl;
			}
		}
		else
			std::cout<<"No items..."<<std::endl;
	}

};

#endif /* INVENTORY_HPP_ */
