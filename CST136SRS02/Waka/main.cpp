// Waka.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cassert>
#include "random"
#include "boat.h"
#include "raft.h"
#include "propulsion.h"
#include "paddle.h"
#include "sail.h"
#include "cardinal.h"
#include "canoe.h" 
#include "wind.h"
#include "sailboat.h"
#include "hull.h"
#include "multiHull.h"
#include "monoHull.h"
#include "chart.h"

int main()
{
	//vars
	auto const upperBound = 30;
	auto const lowerBound = 1;
	auto temp = 0;
	auto paddleStrength = 5;

	auto boatSpeed = 0;
	auto distanceTraveled = 0;

	//rand generator
	std::random_device                  rand_dev;
	std::mt19937                        generator(rand_dev());
	std::uniform_int_distribution<int>  distribution(lowerBound, upperBound);

	//Take a look at the conditions
	Current theCurrent;
	theCurrent.setHeight();
	Wind theWind;
	theWind.setDirection();
	theWind.setSpeed(distribution(generator)); //currently set to default bounds

	//prepare our vessel
	Sailboat mySailboat;
	mySailboat.setName("Thor");
	Canoe myCanoe;
	myCanoe.setName("Loki");
	Raft myRaft(theCurrent.getDirection(), theCurrent.getspeed());
	myRaft.setName("Baldr");
	Chart myChart;

	//warn of the journey ahead
	std::cout << "The journey in your ship voyage begins from the port of Cape Reinga." << std::endl <<
		"You must complete the 5 parts of the voyage to make it safely around NZ back to Cape Reinga:\n" << std::endl <<
		"First goal, 380 miles south" << std::endl <<
		"Second goal, 618 miles southwest" << std::endl <<
		"Third goal, 210 miles southeast" << std::endl <<
		"Fourth goal, 941 miles northeast" << std::endl <<
		"Final goal, 468 miles northwest to Cape Reinga" << std::endl <<
		"This path follows the current around NZ, but you must still be wary of wind and waves!\n\n";


	/*/RAFT###################################################################################################################
	//Start voyage

	std::cout << "Your are traveling in your raft " << myRaft.getName() << "\n\n";

	//first goal
	while (myChart.getMilesFirst() > 0)
	{
		//"Wave height was too high and capsized the boat!
		assert(myRaft.getMaxHeight() >= theCurrent.getHeight());

		//calculate distance traveled
		
		distanceTraveled = theCurrent.getspeed() * 8;
		std::cout << "Traveled " << distanceTraveled << " miles in 8 hours\n" << std::endl;

		//calculate distance left
		myChart.setMilesFirst(distanceTraveled);
		if (myChart.getMilesFirst() <= 0)
		{
			std::cout << "First goal reached, turning to the southwest!\n" << std::endl;

			//reset conditions between turns
			theCurrent.setHeight();
			theCurrent.setSpeed(distribution(generator));
			myRaft.setSpeed(theCurrent.getspeed());
			//strength of paddle decreases with each leg of the voyage
			break;
		}

		theCurrent.setHeight();
		theCurrent.setSpeed(distribution(generator));
		myRaft.setSpeed(theCurrent.getspeed());

	}

	//second goal
	while (myChart.getMilesSecond() > 0)
	{
		//"Wave height was too high and capsized the boat!
		assert(myRaft.getMaxHeight() >= theCurrent.getHeight());

		//calculate distance traveled

		distanceTraveled = theCurrent.getspeed() * 8;
		std::cout << "Traveled " << distanceTraveled << " miles in 8 hours\n" << std::endl;

		//calculate distance left
		myChart.setMilesSecond(distanceTraveled);
		if (myChart.getMilesSecond() <= 0)
		{
			std::cout << "First goal reached, turning to the southeast!\n" << std::endl;

			//reset conditions between turns
			theCurrent.setHeight();
			theCurrent.setSpeed(distribution(generator));
			myRaft.setSpeed(theCurrent.getspeed());
			//strength of paddle decreases with each leg of the voyage
			break;
		}

		theCurrent.setHeight();
		theCurrent.setSpeed(distribution(generator));
		myRaft.setSpeed(theCurrent.getspeed());

	}

	//third goal
	while (myChart.getMilesThird() > 0)
	{
		//"Wave height was too high and capsized the boat!
		assert(myRaft.getMaxHeight() >= theCurrent.getHeight());

		//calculate distance traveled

		distanceTraveled = theCurrent.getspeed() * 8;
		std::cout << "Traveled " << distanceTraveled << " miles in 8 hours\n" << std::endl;

		//calculate distance left
		myChart.setMilesThird(distanceTraveled);
		if (myChart.getMilesThird() <= 0)
		{
			std::cout << "First goal reached, turning to the northeast!\n" << std::endl;

			//reset conditions between turns
			theCurrent.setHeight();
			theCurrent.setSpeed(distribution(generator));
			myRaft.setSpeed(theCurrent.getspeed());
			//strength of paddle decreases with each leg of the voyage
			break;
		}

		theCurrent.setHeight();
		theCurrent.setSpeed(distribution(generator));
		myRaft.setSpeed(theCurrent.getspeed());

	}

	//fourth goal
	while (myChart.getMilesFourth() > 0)
	{
		//"Wave height was too high and capsized the boat!
		assert(myRaft.getMaxHeight() >= theCurrent.getHeight());

		//calculate distance traveled

		distanceTraveled = theCurrent.getspeed() * 8;
		std::cout << "Traveled " << distanceTraveled << " miles in 8 hours\n" << std::endl;

		//calculate distance left
		myChart.setMilesFourth(distanceTraveled);
		if (myChart.getMilesFourth() <= 0)
		{
			std::cout << "First goal reached, turning to the northwest for the final stretch!\n" << std::endl;

			//reset conditions between turns
			theCurrent.setHeight();
			theCurrent.setSpeed(distribution(generator));
			myRaft.setSpeed(theCurrent.getspeed());
			//strength of paddle decreases with each leg of the voyage
			break;
		}

		theCurrent.setHeight();
		theCurrent.setSpeed(distribution(generator));
		myRaft.setSpeed(theCurrent.getspeed());

	}

	//final goal
	while (myChart.getMilesFinal() > 0)
	{
		//"Wave height was too high and capsized the boat!
		assert(myRaft.getMaxHeight() >= theCurrent.getHeight());

		//calculate distance traveled

		distanceTraveled = theCurrent.getspeed() * 8;
		std::cout << "Traveled " << distanceTraveled << " miles in 8 hours\n" << std::endl;

		//calculate distance left
		myChart.setMilesFinal(distanceTraveled);
		if (myChart.getMilesFinal() <= 0)
		{
			std::cout << "Hey, you made it...in a raft somehow...\n" << std::endl;

			//reset conditions between turns
			theCurrent.setHeight();
			theCurrent.setSpeed(distribution(generator));
			myRaft.setSpeed(theCurrent.getspeed());
			//strength of paddle decreases with each leg of the voyage
			break;
		}

		theCurrent.setHeight();
		theCurrent.setSpeed(distribution(generator));
		myRaft.setSpeed(theCurrent.getspeed());

	}
	//RAFT###################################################################################################################*/

	/*/CANOE#################################################################################################################
	//Start journeyvoyagething
	//set direction and speed
	myCanoe.setPaddleStrength(paddleStrength);
	myCanoe.setSpeed(theCurrent.getspeed());


	std::cout << "Your are traveling in your Canoe " << myCanoe.getName() << "\n\n";

	//first goal
	while (myChart.getMilesFirst() > 0)
	{
		//"Wave height was too high and capsized the boat!
		assert(myCanoe.getMaxHeight() >= theCurrent.getHeight());

		//calculate distance traveled
		boatSpeed = myCanoe.getSpeed();
		distanceTraveled = boatSpeed * 8;
		std::cout << "Traveled " << distanceTraveled << " miles in 8 hours\n" << std::endl;

		//calculate distance left
		myChart.setMilesFirst(distanceTraveled);
		if (myChart.getMilesFirst() <= 0)
		{
			std::cout << "First goal reached, turning to the southwest!\n" << std::endl;

			//reset conditions between turns
			theCurrent.setHeight();
			theCurrent.setSpeed(distribution(generator));
			myCanoe.setSpeed(theCurrent.getspeed());
			//strength of paddle decreases with each leg of the voyage
			paddleStrength -= 1;
			myCanoe.setPaddleStrength(paddleStrength);
			break;
		}

		theCurrent.setHeight();
		theCurrent.setSpeed(distribution(generator));
		myCanoe.setSpeed(theCurrent.getspeed());
		
	}
	//second goal
	while (myChart.getMilesSecond() > 0)
	{
		//"Wave height was too high and capsized the boat!
		assert(myCanoe.getMaxHeight() >= theCurrent.getHeight());

		//calculate distance traveled
		boatSpeed = myCanoe.getSpeed();
		distanceTraveled = boatSpeed * 8;
		std::cout << "Traveled " << distanceTraveled << " miles in 8 hours\n" << std::endl;

		//calculate distance left
		myChart.setMilesSecond(distanceTraveled);
		if (myChart.getMilesSecond() <= 0)
		{
			std::cout << "Second goal reached, turning to the southeast!\n" << std::endl;

			//reset conditions between turns
			theCurrent.setHeight();
			theCurrent.setSpeed(distribution(generator));
			myCanoe.setSpeed(theCurrent.getspeed());
			paddleStrength -= 1;
			myCanoe.setPaddleStrength(paddleStrength);
			break;
		}

		theCurrent.setHeight();
		theCurrent.setSpeed(distribution(generator));
		myCanoe.setSpeed(theCurrent.getspeed());

	}
	//third goal
	while (myChart.getMilesThird() > 0)
	{
		//"Wave height was too high and capsized the boat!
		assert(myCanoe.getMaxHeight() >= theCurrent.getHeight());

		//calculate distance traveled
		boatSpeed = myCanoe.getSpeed();
		distanceTraveled = boatSpeed * 8;
		std::cout << "Traveled " << distanceTraveled << " miles in 8 hours\n" << std::endl;

		//calculate distance left
		myChart.setMilesThird(distanceTraveled);
		if (myChart.getMilesThird() <= 0)
		{
			std::cout << "Third goal reached, turning to the northeast!\n" << std::endl;

			//reset conditions between turns
			theCurrent.setHeight();
			theCurrent.setSpeed(distribution(generator));
			myCanoe.setSpeed(theCurrent.getspeed());
			paddleStrength -= 1;
			myCanoe.setPaddleStrength(paddleStrength);
			break;
		}

		theCurrent.setHeight();
		theCurrent.setSpeed(distribution(generator));
		myCanoe.setSpeed(theCurrent.getspeed());

	}
	//fourth goal
	while (myChart.getMilesFourth() > 0)
	{
		//"Wave height was too high and capsized the boat!
		assert(myCanoe.getMaxHeight() >= theCurrent.getHeight());

		//calculate distance traveled
		boatSpeed = myCanoe.getSpeed();
		distanceTraveled = boatSpeed * 8;
		std::cout << "Traveled " << distanceTraveled << " miles in 8 hours\n" << std::endl;

		//calculate distance left
		myChart.setMilesFourth(distanceTraveled);
		if (myChart.getMilesFourth() <= 0)
		{
			std::cout << "Fourth goal reached, turning to the northwest for the final stretch!\n" << std::endl;

			//reset conditions between turns
			theCurrent.setHeight();
			theCurrent.setSpeed(distribution(generator));
			myCanoe.setSpeed(theCurrent.getspeed());
			paddleStrength -= 1;
			myCanoe.setPaddleStrength(paddleStrength);
			break;
		}

		theCurrent.setHeight();
		theCurrent.setSpeed(distribution(generator));
		myCanoe.setSpeed(theCurrent.getspeed());

	}
	//final goal
	while (myChart.getMilesFinal() > 0)
	{
		//"Wave height was too high and capsized the boat!
		assert(myCanoe.getMaxHeight() >= theCurrent.getHeight());

		//calculate distance traveled
		boatSpeed = myCanoe.getSpeed();
		distanceTraveled = boatSpeed * 8;
		std::cout << "Traveled " << distanceTraveled << " miles in 8 hours\n" << std::endl;

		//calculate distance left
		myChart.setMilesFinal(distanceTraveled);
		if (myChart.getMilesFinal() <= 0)
		{
			std::cout << "Congrats bro, you actually made it....bro!\n" << std::endl;

			//reset conditions between turns
			theCurrent.setHeight();
			theCurrent.setSpeed(distribution(generator));
			myCanoe.setSpeed(theCurrent.getspeed());
			paddleStrength -= 1;
			myCanoe.setPaddleStrength(paddleStrength);
			break;
		}

		theCurrent.setHeight();
		theCurrent.setSpeed(distribution(generator));
		myCanoe.setSpeed(theCurrent.getspeed());

	}
	//CANOE###############################################################################################################*/




	//SAILBOAT ###########################################################################################################
	//Start Journey
	//set direction and speed
	
	mySailboat.setDirection(theWind);
	mySailboat.setSpeed(theCurrent, theWind);

	std::cout << "Your are traveling in your sailboat " << mySailboat.getName() << "\n\n";
	
	//first goal
	while(myChart.getMilesFirst() > 0)
	{
		//"Wave height was too high and capsized the boat!
		assert(mySailboat.getMaxHeight() >= theCurrent.getHeight());

		//calculate distance traveled
		boatSpeed = mySailboat.getSpeed();
		distanceTraveled = boatSpeed * 8;
		std::cout << "Traveled " << distanceTraveled << " miles in 8 hours\n" << std::endl;

		//calculate distance left
		myChart.setMilesFirst(distanceTraveled);
		if (myChart.getMilesFirst() <= 0)
		{
			std::cout << "First goal reached, turning to the southwest!\n" << std::endl;

			//reset conditions between turns
			theWind.setDirection();
			theWind.setSpeed(distribution(generator));
			theCurrent.setHeight();
			theCurrent.setSpeed(distribution(generator));
			mySailboat.setSpeed(theCurrent, theWind);
			mySailboat.setDirection(theWind);

			break;
		}

		theWind.setDirection();
		theWind.setSpeed(distribution(generator));
		theCurrent.setHeight();
		theCurrent.setSpeed(distribution(generator));
		mySailboat.setSpeed(theCurrent, theWind);
		mySailboat.setDirection(theWind);
	}

	//second goal
	while (myChart.getMilesSecond() > 0)
	{
		assert(mySailboat.getMaxHeight() >= theCurrent.getHeight());

		//calculate distance traveled 
		boatSpeed = mySailboat.getSpeed();
		distanceTraveled = boatSpeed * 8;
		std::cout << "Traveled " << distanceTraveled << " miles in 8 hours\n" << std::endl;

		//calculate distance left
		myChart.setMilesSecond(distanceTraveled);
		if (myChart.getMilesSecond() <= 0)
		{
			std::cout << "Second goal reached, turning to the southeast!\n" << std::endl;

			//reset conditions between turns
			theWind.setDirection();
			theWind.setSpeed(distribution(generator));
			theCurrent.setHeight();
			theCurrent.setSpeed(distribution(generator));
			mySailboat.setSpeed(theCurrent, theWind);
			mySailboat.setDirection(theWind);

			break;
		}

		theWind.setDirection();
		theWind.setSpeed(distribution(generator));
		theCurrent.setHeight();
		theCurrent.setSpeed(distribution(generator));
		mySailboat.setSpeed(theCurrent, theWind);
		mySailboat.setDirection(theWind);
	}

	//third goal
	while (myChart.getMilesThird() > 0)
	{
		assert(mySailboat.getMaxHeight() >= theCurrent.getHeight());

		//calculate distance traveled 
		boatSpeed = mySailboat.getSpeed();
		distanceTraveled = boatSpeed * 8;
		std::cout << "Traveled " << distanceTraveled << " miles in 8 hours\n" << std::endl;

		//calculate distance left
		myChart.setMilesThird(distanceTraveled);
		if (myChart.getMilesSecond() <= 0)
		{
			std::cout << "Third goal reached, turning to the northeast\n" << std::endl;

			//reset conditions between turns
			theWind.setDirection();
			theWind.setSpeed(distribution(generator));
			theCurrent.setHeight();
			theCurrent.setSpeed(distribution(generator));
			mySailboat.setSpeed(theCurrent, theWind);
			mySailboat.setDirection(theWind);

			break;
		}

		theWind.setDirection();
		theWind.setSpeed(distribution(generator));
		theCurrent.setHeight();
		theCurrent.setSpeed(distribution(generator));
		mySailboat.setSpeed(theCurrent, theWind);
		mySailboat.setDirection(theWind);
	}

	
	//fourth goal
	while (myChart.getMilesFourth() > 0)
	{
		assert(mySailboat.getMaxHeight() >= theCurrent.getHeight());

		//calculate distance traveled 
		boatSpeed = mySailboat.getSpeed();
		distanceTraveled = boatSpeed * 8;
		std::cout << "Traveled " << distanceTraveled << " miles in 8 hours\n" << std::endl;

		//calculate distance left
		myChart.setMilesFourth(distanceTraveled);
		if (myChart.getMilesSecond() <= 0)
		{
			std::cout << "Fourth goal reached, turning to the northwest for the final stretch!\n" << std::endl;

			theWind.setDirection();
			theWind.setSpeed(distribution(generator));
			theCurrent.setHeight();
			theCurrent.setSpeed(distribution(generator));
			mySailboat.setSpeed(theCurrent, theWind);
			mySailboat.setDirection(theWind);

			break;
		}

		theWind.setDirection();
		theWind.setSpeed(distribution(generator));
		theCurrent.setHeight();
		theCurrent.setSpeed(distribution(generator));
		mySailboat.setSpeed(theCurrent, theWind);
		mySailboat.setDirection(theWind);
	}

	//final goal
	while (myChart.getMilesFourth() > 0)
	{
		assert(mySailboat.getMaxHeight() >= theCurrent.getHeight());

		//calculate distance traveled 
		boatSpeed = mySailboat.getSpeed();
		distanceTraveled = boatSpeed * 8;
		std::cout << "Traveled " << distanceTraveled << " miles in 8 hours\n" << std::endl;

		//calculate distance left
		myChart.setMilesFourth(distanceTraveled);
		if (myChart.getMilesSecond() <= 0)
		{
			std::cout << "Congrats bro, you actually made it....bro!\n" << std::endl;
			break;
		}

		theWind.setDirection();
		theWind.setSpeed(distribution(generator));
		theCurrent.setHeight();
		theCurrent.setSpeed(distribution(generator));
		mySailboat.setSpeed(theCurrent, theWind);
		mySailboat.setDirection(theWind);
	}
	//SAILBOAT########################################################################################################################*/

	std::cin >> temp;

    return 0;
}

