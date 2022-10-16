#include "BaseText.h"

bool BaseText::writeNumbers()
{
	bool pause{ true };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
	{
		updateText('0');
		pause = false;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		updateText('1');
		pause = false;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		updateText('2');
		pause = false;
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		updateText('3');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
	{
		updateText('4');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
	{
		updateText('5');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
	{
		updateText('6');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
	{
		updateText('7');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
	{
		updateText('8');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
	{
		updateText('9');
		pause = false;
	}

	return pause;
}

bool BaseText::writeLetters()
{
	bool pause{ true };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		updateText(' ');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Hyphen))
	{
		updateText('-');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		updateText('a');
		pause = false;

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
		updateText('b');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		updateText('c');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		updateText('d');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		updateText('e');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		updateText('f');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
	{
		updateText('g');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
	{
		updateText('h');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
	{
		updateText('i');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
	{
		updateText('j');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
	{
		updateText('k');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{
		updateText('l');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		updateText('m');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
	{
		updateText('n');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
	{
		updateText('o');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		updateText('p');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		updateText('q');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		updateText('r');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		updateText('s');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		updateText('t');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
	{
		updateText('u');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
	{
		updateText('v');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		updateText('w');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		updateText('x');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
	{
		updateText('y');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		updateText('z');
		pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Comma))
	{
	updateText(',');
	pause = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Period))
	{
	updateText('.');
	pause = false;
	}

	return pause;
}