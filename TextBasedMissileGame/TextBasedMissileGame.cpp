// TextBasedMissileGame.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "TextBasedMissileGame.h"

int main()
{
	enum Warhead { Ballistic, Nuclear };
	Missile missile;
	Warhead missileType;
	Userinputs userinputs;

	//Phase 1: Selecting Rocket Type
	cout << "( u w u )" << endl;
	cout << "Pwease sewect youw wawhead (0 fow weguwaw boom, 1 fow nucweaw boom!!!) " << endl;
	cin >> userinputs.userMissileChoice;

	while (userinputs.userMissileChoice > 1)
	{
		cout << "( > ~ < )" << endl;
		cout << "Invawid sewection mmm.. pwease pick a number f-fwom 0 to 1 nya~" << endl;
		cin >> userinputs.userMissileChoice;
	}

	//Cast missile choice as an int into the enum
	switch (userinputs.userMissileChoice)
	{
	case 0:
		system("CLS");
		missileType = Warhead::Ballistic;
		cout << "( o u o )7" << endl;
		cout << "Bawwistic missile sewected" << endl << endl;
		system("PAUSE");
		break;
	case 1:
		system("CLS");
		missileType = Warhead::Nuclear;
		cout << "( 0 U 0 )7" << endl;
		cout << "N U C W E A W missile sewected!!!!" << endl << endl;
		system("PAUSE");
		break;
	}

	//Phase 2: Selecting strike coordinates
	system("CLS");
	cout << "( o w o )" << endl;
	cout << "p-pwease designate youw stwike coowdinates" << endl << endl;


	cout << "pwease e-enter the x coowdinate" << endl;
	cin >> userinputs.coordinates.x;

	while (userinputs.coordinates.x > BATTLEFIELD_MAX_SIZE_X || userinputs.coordinates.x < BATTLEFIELD_MIN_SIZE_X)
	{
		cout << "( /) ~ (\)" << endl;
		cout << "Uwaaaaa..thats out of bounds! pwease pick a number f-fwom 1 to 5 nya~" << endl;
		cin >> userinputs.coordinates.x;
	}

	cout << "pwease e-enter the y coowdinate" << endl;
	cin >> userinputs.coordinates.y;
	while (userinputs.coordinates.y > BATTLEFIELD_MAX_SIZE_Y || userinputs.coordinates.y < BATTLEFIELD_MIN_SIZE_Y)
	{
		cout << "( /) ~ (\)" << endl;
		cout << "Uwaaaaa..thats out of bounds! pwease pick a number f-fwom 1 to 5 nya~" << endl;
		cin >> userinputs.coordinates.y;
	}

	system("CLS");

	//Phase 3: Arming the missile
	cout << "{0 -  o]" << endl;
	cout << "Your actions will have disastrous consequences. Do you wish to continue? If so, key in the launch code." << endl << endl;
	cin >> userinputs.userLaunchCode;
	system("CLS");

	if (userinputs.userLaunchCode == LAUNCH_CODE)
	{
		isArmed = true;
		cout << "(   > o < )/)" << endl;
		cout << "Missile armed, ikuzo!!!!!!" << endl;
		missile.coordinates.x = 0;
		missile.coordinates.y = 0;

		srand(time(NULL));
		for (int i = 0; i < ENEMY_COUNT; i++)
		{
			missile.targets[i].coordinates.x = rand() % 5 + 1;
			missile.targets[i].coordinates.y = rand() % 5 + 1;
			//missile.targets[i].coordinates.coordinates.push_back(pair<int, int>(i, i));
		}
		isRunning = true;
	}

	else
	{
		isArmed = false;
		missile.coordinates.x = 0;
		missile.coordinates.y = 0;
		cout << "{V -  u]" << endl;
		cout << "And the world lives to see another day." << endl << endl;
		exit;
	}

	//Phase 4: Handling missile collisions
	while (isRunning = true)
	{
		
		switch (missile.payload)
		{
		case Ballistic:
			if (missile.coordinates.x == userinputs.coordinates.x && missile.coordinates.y == userinputs.coordinates.y)
			{
				for (int i; i < ENEMY_COUNT; i++)
				{
					if (missile.targets[i].coordinates.x == missile.coordinates.x || (missile.targets[i].coordinates.y == missile.coordinates.y)
					{
						
					}
				}
			}



		case Nuclear:		
			if (missile.coordinates.x == userinputs.coordinates.x && missile.coordinates.y == userinputs.coordinates.y)
			{

			}
	
		system("PAUSE");
		}
	}
}

