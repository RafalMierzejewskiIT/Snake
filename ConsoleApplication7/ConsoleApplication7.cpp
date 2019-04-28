#include "pch.h"
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include "curses.h"
#include "Screen.h"
#include "Entity.h"
#include "Direction.h"
#include "Apple.h"

const short int STARTING_PLAYER_LENGTH = 3;
short int player_length = STARTING_PLAYER_LENGTH;
int highscore = 0;

void gameDecay(short int pixel[Entity::RES_WIDTH][Entity::RES_HEIGHT]);
short int selectCheck(short int &check_number, short int min, short int max);

int main()
{
	srand(time(NULL));
	system("MODE CON COLS=97 LINES=30");

	short int pixel[Entity::RES_WIDTH][Entity::RES_HEIGHT];
	short int player_x = (Entity::RES_WIDTH/2);
	short int player_y = (Entity::RES_HEIGHT/4);
	short int game_speed = 0;

	Screen::drawWalls(pixel);		// Creates collision walls outside the Screen

	std::cout << "Select game speed (1-3): ";
	selectCheck(game_speed,1,3);
	game_speed = 40 - (game_speed * 5);

	initscr();

	while (1)
	{
		if (player_length == (Entity::RES_WIDTH*Entity::RES_HEIGHT) - STARTING_PLAYER_LENGTH)
		{
			clear();
			printw("You've beaten the game");
			break;
		}
		Direction::inputUpdate();
		if (Direction::get_inputCounter() == (game_speed))
		{
			clear();
			Apple::newApple(pixel);
			Direction::all_dir(player_x, player_y);
																// pixel[player_x][player_y] is player position in next generated frame
			if (pixel[player_x][player_y] <= -1)				// eating an apple
			{
				highscore -= pixel[player_x][player_y];
				player_length++;
				Apple::set_apple_counter(0);
			}
			if (pixel[player_x][player_y] >= 1)					// hitting a wall or eating yourself
			{
				if ((pixel[player_x][player_y] == 1) && ( player_x == 0 || player_x == Entity::RES_WIDTH-1 || player_y == 0 || player_y == Entity::RES_HEIGHT-1))
					break;
				for (int i = 0; i < 5; i++)						// if you eat yourself, the head will flicker
				{
					clear();
					pixel[player_x][player_y] = 1;
					if (i % 2 == 0)
						pixel[player_x][player_y] = 0;
					Screen::drawScreen(pixel);
					refresh();
					Sleep(175);
				}
				break;
			}
			if (Apple::get_apple_counter() == 1)				// corrects snakes length increase    right after eating an apple
			gameDecay(pixel);
			pixel[player_x][player_y] = player_length;
			
			Screen::drawScreen(pixel);
			refresh();
		}
	}
	endwin();
	std::cout<<std::endl;
	std::cout << "Your highscore is: " << highscore << std::endl;
	return 0;
}

void gameDecay(short int pixel[Entity::RES_WIDTH][Entity::RES_HEIGHT])
{
	for (int y = 1; y < Entity::RES_HEIGHT - 1; y++)
	{
		for (int x = 1; x < Entity::RES_WIDTH - 1; x++)
		{
			if (pixel[x][y] >= 1)
				pixel[x][y]--;
			if (pixel[x][y] < -1)
				pixel[x][y]++;
			if (pixel[x][y] == -1)				// -1 means apple will cease to exist in next frame
			{
				pixel[x][y]++;
				Apple::set_apple_counter(0);	// will ensure to create another apple in next frame
			}
		}
	}
}

short int selectCheck(short int &check_number, short int min, short int max)
{
	while (1)
	{
		std::cin >> check_number;
		if (check_number >= min && check_number <= max)
		{
			return check_number;
			break;
		}
		else
			std::cout << "Invalid number\n";	
	}
}