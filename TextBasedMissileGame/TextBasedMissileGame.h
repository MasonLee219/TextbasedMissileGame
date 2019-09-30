#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

int const BATTLEFIELD_MAX_SIZE_X = 5;
int const BATTLEFIELD_MAX_SIZE_Y = 5;
int const BATTLEFIELD_MIN_SIZE_X = 1;
int const BATTLEFIELD_MIN_SIZE_Y = 1;
int const ENEMY_COUNT = 3;
int const LAUNCH_CODE = 1234;

enum Warhead { Ballistic, Nuclear };

bool isArmed = false;
bool isRunning = false;

typedef struct Position
{	
	int x;
	int y;
	vector<vector<pair<int, int>>> coordinates;

	void print()
	{
		cout<< "(" << x <<"," << y << ")"<< endl;
	}
}Coordinates;

struct Userinputs
{
	Coordinates coordinates;
	int userMissileChoice;
	int userLaunchCode;
};

typedef struct Enemy
{
	Coordinates coordinates;
	void kill()
	{
		delete this;
	}
}Target;


struct Missile
{
	Warhead payload;
	Coordinates coordinates;

	Target targets[ENEMY_COUNT];

	bool armed;

	void arm()
	{
		if (isArmed)
			isArmed = false;
		else
			isArmed = true;
	}

	void updateX()
	{
		coordinates.x += 1;
	}

	void updateY()
	{
		coordinates.y += 1;
	}
};






