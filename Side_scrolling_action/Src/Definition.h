#ifndef DEFINITION_H
#define DEFINITION_H

#include"DxLib.h"

const int WindowSizeX = 1000;
const int WindowSizeY = 600;

enum class Scene
{
	title,
	game,
	result
};

enum Ability
{
	a,
	s,
	d,
	f,
	none
};

enum class KeyState
{
	none,
	push,
	hold,
	release
};
 
#endif // !DEFINITION_H

