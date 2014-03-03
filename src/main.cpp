/*
 * main.cpp
 *
 *  Created on: 7 feb 2014
 *      Author: findus
 */
#include <iostream>
#include <vector>
#include <memory> //for smart pointers

#include "Testing.hpp"
#include "TheGame.hpp"

int main(){

	int my_array[5] = {1, 2, 3, 4, 5};
	// double the value of each element in my_array:
	for (int &x : my_array) {
	    x *= 2;
	}
	// similar but also using type inference for array elements
	for (auto &x : my_array) {
	    x *= 2;
	}


//	test_Room();
//	test_Player();
//	test_attack();
//	test_FighterVector();


//-------------------------------------------------------------------------
	TheGame g;
	g.playTheGame();

	return 0;

}


