#pragma once
#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "Screen.h"

// the sizes of the screen created
namespace screenSize
{
	inline constexpr int x{ 800 };
	inline constexpr int y{ 600 };
}

namespace ScreenState
{
	inline Screen screen{ Screen::menu }; // 0 = menu, 1 = create list, 2 = view lists
}

namespace CreationStep
{
	inline Render state{ Render::naming };
}

namespace ChooseView
{
	inline Viewing step{ Viewing::none };
}

#endif
