// TextBasedMissileGame.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "TextBasedMissileGame.h"


//The features two characters, (o w o) and {0 -  o], and the player.
// (o w o) is a japanese warmongerer who is trying to nuke the world into submission to cripple governments and seize nations. 
// {0 -  o] is an pacifist who has suffered the effect of nuclear war and is trying to prevent the fate that fell upon his land to affect the entire world
// The ending and fate of the land falls on the players hand, and whoever he aligns with decides the ending

int main()
{
	enum Warhead { Ballistic, Nuclear };
	Missile missile;
	Warhead missileType;
	Userinputs userinputs;

	//Phase 1: Selecting Rocket Type
	cout << "\t\t Cutesy Wutesy Nukey Gamey!!!" << endl << endl <<endl;
	cout << "( u w u )" << endl;
	cout << "Pwease sewect youw wawhead (0 fow weguwaw boom, 1 fow nucweaw boom!!!) " << endl;
	cin >> userinputs.userMissileChoice;

	while (userinputs.userMissileChoice > 1)
	{
		cout << "\t\t Cutesy Wutesy Nukey Gamey!!!" << endl << endl << endl;
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
		cout << "\t\t Cutesy Wutesy Nukey Gamey!!!" << endl << endl << endl;
		cout << "( o u o )7" << endl;
		cout << "Bawwistic missile sewected" << endl << endl;
		system("PAUSE");
		break;
	case 1:
		system("CLS");
		missileType = Warhead::Nuclear;
		cout << "\t\t Cutesy Wutesy Nukey Gamey!!!" << endl << endl << endl;
		cout << "( 0 U 0 )7" << endl;
		cout << "N U C W E A W missile sewected!!!!" << endl << endl;
		system("PAUSE");
		break;
	}

	//Phase 2: Selecting strike coordinates
	system("CLS");
	cout << "\t\t Cutesy Wutesy Nukey Gamey!!!" << endl << endl << endl;
	cout << "( o w o )" << endl;
	cout << "p-pwease designate youw stwike coowdinates" << endl << endl;


	cout << "pwease e-enter the x coowdinate" << endl;
	cin >> userinputs.coordinates.x;

	//Checks if the player's input is within the battlefield size. If not, it prompts the user to enter another options
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
	cout << "\t\t Mass Murder Simulator" << endl << endl << endl;
	cout << "{0 -  o]" << endl;
	cout << "Your actions will have disastrous consequences. Do you wish to continue? If so, key in the launch code." << endl << endl;
	cin >> userinputs.userLaunchCode;
	system("CLS");

	if (userinputs.userLaunchCode == LAUNCH_CODE)
	{
		//Arms the misile and sets the coordinates for the missile
		isArmed = true;
		cout << "\t\t Cutesy Wutesy Nukey Gamey!!!" << endl << endl << endl;
		cout << "(   > o < )/)" << endl;
		cout << "Missile armed, ikuzo!!!!!!" << endl;
		missile.coordinates.x = 0;
		missile.coordinates.y = 0;

		//Spawns the enemies
		srand(time(NULL));
		for (int i = 0; i < ENEMY_COUNT; i++)
		{
			missile.targets[i].coordinates.x = rand() % 5 + 1;
			missile.targets[i].coordinates.y = rand() % 5 + 1;			
		}
		isRunning = true;
	}

	else
	{
		isArmed = false;
		missile.coordinates.x = 0;
		missile.coordinates.y = 0;
		cout << "\t\t Cutesy Wutesy Nukey Gamey!!!" << endl << endl << endl;
		cout << "{V -  u]" << endl;
		cout << "And the world lives to see another day." << endl << endl;
		exit;
	}

	//Phase 4: Handling missile collisions
	//Main game loop
	while (isRunning == true)
	{
		//Prints the missile coordinates while it is travelling to the target
		while (missile.coordinates.x != userinputs.coordinates.x)
		{
			missile.updateX();
			cout << "Missile coordinates:";
			missile.coordinates.print();
		}

		while (missile.coordinates.y != userinputs.coordinates.y)
		{
			missile.updateY();
			cout << "Missile coordinates:";
			missile.coordinates.print();
		}

		if (missile.coordinates.x == userinputs.coordinates.x && missile.coordinates.y == userinputs.coordinates.y)
		{
			switch (missileType)
			{
			case Warhead::Ballistic:
				//loops through all the enemies and sees if it hits any of them
				for (int i = 0; i < ENEMY_COUNT;i++)
				{
					if (missile.targets[i].coordinates.x == missile.coordinates.x && missile.targets[i].coordinates.y == missile.coordinates.y)
					{						
						cout << "( ^ o ^ )" << endl;
						cout << "Hit!!!" << endl;						
						break;
					}					
				}
				cout << "( > ~ < )" << endl;
				cout << "Miss!! You have kiwwed 3 innocent fawmews!" << endl; 
				break;
				
				
			
			//Nuclear missile range is 5 x 5, and kills everything on the battlefield
			case Warhead::Nuclear:
				if (missile.coordinates.x == userinputs.coordinates.x && missile.coordinates.y == userinputs.coordinates.y)
				{				
					system("cls");

					system("PAUSE");
					system("cls");
					cout << "\t\t Mass Murder Simulator" << endl << endl << endl;
					cout << "{0 -  o]" << endl;		

					system("PAUSE");
					system("cls");
					cout << "\t\t Mass Murder Simulator" << endl << endl << endl;
					cout << "{0 -  o]" << endl;
					cout << "Congratulations, you killed everything." << endl << endl;
					
					system("PAUSE");
					system("cls");
					cout << "\t\t Mass Murder Simulator" << endl << endl << endl;
					cout << "{0 -  o]" << endl;
					cout << "You won the game." << endl << endl;
				
					system("PAUSE");
					system("cls");
					cout << "\t\t Mass Murder Simulator" << endl << endl << endl;
					cout << "{ 0 -   O]" << endl;
					cout << "D    o  y 0  u    f e3l   l1k e a her0  y3 t?" << endl << endl;
				}
			}
			break;
		}
	}
	system("PAUSE");
}


