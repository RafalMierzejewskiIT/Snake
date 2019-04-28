#include "pch.h"
#include "Screen.h"
#include "curses.h"

void Screen::drawWalls(short int pixel[RES_WIDTH][RES_HEIGHT])
{
	for (int y = 0; y < RES_HEIGHT; y++)
	{
		for (int x = 0; x < RES_WIDTH; x++)
		{
			if (x == 0 || y == 0 || x == RES_WIDTH - 1 || y == RES_HEIGHT - 1)
				pixel[x][y] = 1;
			else
				pixel[x][y] = 0;
		}
	}
}

void Screen::drawScreen(short int pixel[RES_WIDTH][RES_HEIGHT])
{
	for (int y = 1; y < RES_HEIGHT - 1; y++)
	{
		for (int x = 1; x < RES_WIDTH - 1; x++)
		{
			if (pixel[x][y] >= 1)
				addch(9608);
			else if (pixel[x][y] == 0)
				addch(160);
			else if (pixel[x][y] <= 1)
				addch(9619);
			else
				addch(pixel[x][y]);
		}
	}
}


Screen::Screen()
{
}


Screen::~Screen()
{
}
