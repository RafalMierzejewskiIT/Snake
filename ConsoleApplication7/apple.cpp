#include "pch.h"
#include "apple.h"
#include <time.h>
#include <stdlib.h>

short int Apple::apple_counter = 0;
short int Apple::apple_timer = -150;	// How many drawScreen calls will apple exist, negative for game logic purposes
short int Apple::apple_x = 0;
short int Apple::apple_y = 0;

void Apple::newApple(short int pixel[RES_WIDTH][RES_HEIGHT])
{
	while (apple_counter == 0) {
		apple_x = rand() % (RES_WIDTH - 2) + 1;
		apple_y = rand() % (RES_HEIGHT - 2) + 1;
		if (pixel[apple_x][apple_y] == 0)
		{
			pixel[apple_x][apple_y] = apple_timer;
			apple_counter++;
		}
	}
}


Apple::Apple()
{
}


Apple::~Apple()
{
}
