#pragma once
#ifndef SCREEN_H
#define SCREEN_H

enum class Screen
{
	menu,
	creation,
	view,
	deleting,
};

enum class Render
{
	naming,
	sizing,
	writing,
};

enum class Texture 
{ 
	standard, 
	hover,
};

enum class Viewing
{
	lists, 
	item, 
	none,
};

enum class Direction
{
	left,
	right,
};

#endif // !SCREEN_H