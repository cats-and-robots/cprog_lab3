/*
 * Object.hpp
 *
 *  Created on: 7 feb 2014
 *      Author: findus
 */

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <iostream>
#include <string>

class Object{
protected:
	std::string name_;
	std::string info_;
	std::string use_code_;
	int use_value_;

public:

	virtual ~Object(){};

	virtual std::string type() const = 0;
	virtual int getATK() const = 0;
	virtual int getDEF() const = 0;
	std::string name() const{return name_;}
	std::string info() const{return info_;}
	std::string use_code() const{return use_code_;}
	int use_value() const{return use_value_;}
	std::string baseType() const{return "Object";}


};

#endif /* OBJECT_HPP_ */
