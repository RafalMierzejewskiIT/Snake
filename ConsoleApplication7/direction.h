#pragma once

class Direction
{
private:
	static short int inputCounter;
	static char last_direction;
	static char direction;
	static bool isReverse;
public:
	static char inputUpdate();
	static short int get_inputCounter() { return Direction::inputCounter; }
	static void change_direction(short int &player_x, short int &player_y);
	static void all_dir(short int &player_x, short int &player_y);
	short int set_inputCounter(short int var) { Direction::inputCounter = var; return var; }
	
	Direction();
	~Direction();
};

