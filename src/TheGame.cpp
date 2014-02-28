/*
 * TheGame.cpp
 *
 *  Created on: 7 feb 2014
 *      Author: findus
 */
#include <iostream>
#include <vector>
#include <memory> //for smart pointers

#include "Testing.hpp"


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
	/*
	std::cout<<"\n------------Testing Cat-class!------------"<<std::endl;
	Cat c1("Siamese");
	std::cout<<c1<<std::endl;
	std::cout<<"Calling currentHP(): "<<c1.currentHP()<<std::endl;
	std::cout<<"Calling attack(): "<<c1.attack()<<std::endl;
	std::cout<<"Calling Roar()"<<std::endl;
	c1.Roar();
	Cat c2("Scottish fold", 100, 10,20);
	c2.takeDamage(3);
	std::cout<<"Called takeDamage(3)"<<std::endl;
	std::cout<<c2<<std::endl;
	std::cout<<"Calling Roar()"<<std::endl;
	c2.Roar();


	std::cout<<"\n------------Testing EvilCat-class!------------"<<std::endl;
	EvilCat ec1("MadCat");
	std::cout<<ec1<<std::endl;
	std::cout<<"Calling currentHP(): "<<ec1.currentHP()<<std::endl;
	std::cout<<"Calling attack(): "<<ec1.attack()<<std::endl;
	std::cout<<"Calling Roar()"<<std::endl;
	ec1.Roar();
	EvilCat ec2("Sgt Meowth", 100,10,8);
	ec2.takeDamage(3);
	std::cout<<"Called takeDamage(3)"<<std::endl;
	std::cout<<ec2<<std::endl;
	std::cout<<"Calling Roar()"<<std::endl;
	ec2.Roar();


	std::cout<<"\n------------Testing Item-class!------------"<<std::endl;
	Item i1("Google glass", "Glasses to translate japanese to english");
	std::cout<<i1<<std::endl;
	Item i2("Key", "Magic Key");

	std::cout<<"\n------------Testing Weapon-class!------------"<<std::endl;
	Weapon w1("Axe", "Heavy Axe", 10,3);
	std::cout<<w1<<std::endl;
	std::cout<<"Called getATK(): "<<w1.getATK() << std::endl;
	std::cout<<"Calling getDEF: "<<w1.getDEF() << std::endl;
	std::cout<<"Calling baseType()..."<<std::endl;
	std::cout<<w1.baseType()<<std::endl;
	Weapon w2("Sword", "A long broad sword", 10,1);

	std::cout<<"\n------------Testing CafeRobot-class!------------"<<std::endl;
	CafeRobot cr1("Asimo");
	std::cout<<cr1<<std::endl;
	std::cout<<"Called Talk(): "<< std::endl;
	cr1.Talk();

	std::cout<<"\n------------Testing EvilRobot-class!------------"<<std::endl;
	EvilRobot er1("Terminator");
	std::cout<<er1<<std::endl;
	std::cout<<"Calling Talk(): "<<std::endl;
	er1.Talk();
	std::cout<<er1<<std::endl;

	std::unique_ptr<Object> wep1(new Weapon("Axe", "Heavy Axe", 10,3));
	EvilRobot er2("PetaMan", 10, std::move(wep1));
	std::cout<<er2<<std::endl;
	std::cout<<"Calling Talk(): "<<std::endl;
	er2.Talk();
	std::cout<<er2<<std::endl;
	std::cout<<*(er2.getItem())<<std::endl;
	std::unique_ptr<Object> weap_temp = er1.getItem();
	if (weap_temp == NULL){
		std::cout<<"EMPTY!"<<std::endl;
	}




	std::cout<<"\n------------Testing EvilCatRobot-class!------------"<<std::endl;
	EvilCatRobot ecr1("Mekka Catzilla");
	std::cout<<ecr1<<std::endl;
	std::cout<<"Calling Talk(): "<<std::endl;
	ecr1.Talk();
	std::cout<<ecr1<<std::endl;
	std::cout<<"Calling Roar(): "<<std::endl;
	ecr1.Roar();

	std::unique_ptr<Object> wep1(new Weapon("Axe", "Heavy Axe", 10,3));
	EvilCatRobot ecr2("Catastrophos",
			100 ,50 , 70, 5, std::move(wep1) );
	std::cout<<ecr2<<std::endl;
	std::cout<<"Calling Talk(): "<<std::endl;
	ecr2.Talk();
	std::cout<<ecr2<<std::endl;
	std::cout<<"Calling Roar(): "<<std::endl;
	ecr2.Roar();
	std::cout<<"Calling baseType()..."<<std::endl;
	std::cout<<ecr2.baseType()<<std::endl;



	std::cout<<"\n------------Testing slicing EvilCat to Cat!------------"<<std::endl;
	Cat niceCat(ec1);
	std::cout<<niceCat<<std::endl;
	std::cout<<"Calling Roar(): "<<std::endl;
	niceCat.Roar();
	std::cout<<"Calling baseType()..."<<std::endl;
	std::cout<<niceCat.baseType()<<std::endl;

	*/

	test_Room();
//	test_Player();
//	test_attack();
//	test_FighterVector();

	return 0;
}


