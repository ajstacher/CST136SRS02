// Waka.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "boat.h"
#include "propulsion.h"
#include "paddle.h"
#include "cardinal.h"

int main()
{
	int temp = 0;

	Paddle paddle;

	paddle.setStrength(2);
	paddle.setSpeed(100);

	std::cout << paddle.getSpeed();

	
	//Cardinal sailDirection = Cardinal::N;


	/*Boat myboat;
	std::string boatName = "poop";

	boatName = myboat.getName();
	std::cout << boatName << std::endl;

	myboat.setName("Thor");

	std::cout << myboat.getName() <<std::endl;*/

	//wait
	std::cin >> temp;

    return 0;
}

