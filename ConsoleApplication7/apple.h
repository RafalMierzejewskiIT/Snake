#pragma once
#include "Entity.h"

class Apple: public Entity
{
private:
	static short int apple_counter;
	static short int apple_timer;
	static short int apple_x;
	static short int apple_y;
public:
	static void newApple(short int pixel[RES_WIDTH][RES_HEIGHT]);
	static void set_apple_counter(short int set) { apple_counter = set; }
	static short int get_apple_counter() { return apple_counter; }
	Apple();
	~Apple();
};

