/*
 * Inventory.cpp
 *
 *  Created on: 19 feb 2014
 *      Author: findus
 */

#include "Inventory.hpp"

Inventory::Inventory(){}
Inventory::~Inventory(){}

void Inventory::put(std::unique_ptr<Object> item){
	items_.insert (std::pair< std::string, std::unique_ptr<Object> >
		(item->name(),std::move(item)) );
}

void Inventory::put_all(std::vector< std::unique_ptr<Object> >& items){
	while( !items.empty() ){
		this->put( std::move( items.back() ) );
		items.pop_back();
	}
}

std::unique_ptr<Object> Inventory::take(std::string name){
	for (auto iter = items_.find(name); iter != items_.end(); ++iter){
		if (iter->first == name){
			std::unique_ptr<Object> thing = std::move(iter->second);
			items_.erase(iter);
			return std::move(thing);
		}
	}
	return nullptr;
}

void Inventory::show_inventory() const{
	int counter = 1;
	std::cout<<"Inventory:"<<std::endl;
	if (!this->isEmpty() ){
		for (auto iter = items_.begin(); iter != items_.end(); ++iter){
			std::cout<< counter++ <<": <"<< iter->second->type()<< "> " <<iter->first<<std::endl;
		}
	}
	else
		std::cout<<"Empty"<<std::endl;
}

bool Inventory::isEmpty() const{
	if (items_.size() == 0 )
		return true;
	else
		return false;
}

std::vector<std::string> Inventory::get_items_name() const{
	std::vector<std::string> names;
	for (auto iter = items_.begin(); iter != items_.end(); ++iter){
		if (iter->second->type() == "Item")
			names.push_back(iter->first);
	}
	return names;
}

std::vector<std::string> Inventory::get_weapons_name() const{
	std::vector<std::string> names;
	for (auto iter = items_.begin(); iter != items_.end(); ++iter){
		if (iter->second->type() == "Weapon")
			names.push_back(iter->first);
	}
	return names;
}

std::vector< std::unique_ptr<Object> >  Inventory::loot(){
	std::vector< std::unique_ptr<Object> > loot;
	while( !items_.empty() ){
		auto iter = items_.begin();
		std::unique_ptr<Object> item = std::move(iter->second);
		items_.erase(iter);
		loot.push_back( std::move(item) );
	}

//	for (auto iter = items_.begin(); iter != items_.end(); ++iter){
//		std::unique_ptr<Object> thing = std::move(iter->second);
//		items_.erase(iter);
//		loot.push_back( std::move(thing) );
//	}

	return loot;
}
