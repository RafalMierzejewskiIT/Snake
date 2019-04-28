#pragma once
#include "Entity.h"

class Screen: public Entity
{
public:
	static void drawWalls(short int pixel[RES_WIDTH][RES_HEIGHT]);
	static void drawScreen(short int pixel[RES_WIDTH][RES_HEIGHT]);
	Screen();
	~Screen();
};