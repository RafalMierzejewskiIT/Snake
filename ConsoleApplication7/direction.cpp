#include "pch.h"
#include "Direction.h"
#include <Windows.h>

short int Direction::inputCounter = 0;
char Direction::last_direction;
char Direction::direction = 's';
bool Direction::isReverse;

char Direction::inputUpdate()
{
	if (GetKeyState('W') & 0x8000)
	{
		direction = 'w';
	}
	if (GetKeyState('A') & 0x8000)
	{
		direction = 'a';
	}
	if (GetKeyState('S') & 0x8000)
	{
		direction = 's';
	}
	if (GetKeyState('D') & 0x8000)
	{
		direction = 'd';
	}
	inputCounter++;
	Sleep(1);
	return direction;
}

void Direction::change_direction(short int &player_x, short int &player_y)
{
	switch (direction)
	{
	case 'w':
		if (last_direction != 's')
		{
			player_y--;
			isReverse=false;
		}
		else
			player_y++;
		break;
	case 'a':
		if (last_direction != 'd')
		{
			player_x--;
			isReverse=false;
		}
		else player_x++;
		break;
	case 's':
		if (last_direction != 'w')
		{
			player_y++;
			isReverse=false;
		}
		else player_y--;
		break;
	case 'd':
		if (last_direction != 'a')
		{
			player_x++;
			isReverse=false;
		}
		else player_x--;
		break;
	}
}

void Direction::all_dir(short int &player_x, short int &player_y)
{
	inputCounter=0;
	isReverse=true;
	change_direction(player_x, player_y);
	if (isReverse == false)							// Disabling the possibility to eat yourself by changing to backwards direction
		last_direction = direction;
}

Direction::Direction()
{
}


Direction::~Direction()
{
}