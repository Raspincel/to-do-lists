#include "Option.h"

void Option::setFont()
{
	if (!m_font.loadFromFile("Fonts/RobotoMono-Regular.ttf"))
		std::cerr << "Failure in loading font" << '\n';
}

void Option::setText()
{
    m_text.setFont(m_font);
    m_text.setLetterSpacing(1.5);
    m_text.setFillColor(sf::Color::White);
    m_text.setLineSpacing(2.0);
    m_text.setCharacterSize(21);

    m_number.setFont(m_font);
    m_number.setLetterSpacing(1.5);
    m_number.setFillColor(sf::Color::White);
    m_number.setLineSpacing(2.0);
    m_number.setCharacterSize(18);
}

void Option::setOutline()
{
    m_text.setOutlineColor(sf::Color::Green);
    m_text.setOutlineThickness(1);
    m_number.setOutlineColor(sf::Color::Green);
    m_number.setOutlineThickness(1);
}

void Option::removeOutline()
{
    m_text.setOutlineThickness(0);
    m_text.setOutlineColor(sf::Color(0, 0, 0, 0));
    m_number.setOutlineThickness(0);
    m_number.setOutlineColor(sf::Color(0, 0, 0, 0));
}


void Option::outline(const sf::Vector2f& mousePos)
{
    if (m_text.getOutlineColor() == sf::Color::Red)
        return;

    bool hovering{ isHovering(mousePos) };

    if (hovering && m_texture == Texture::standard)
    {
        setOutline();
        m_texture = Texture::hover;
    }
    else if (!hovering && m_texture == Texture::hover)
    {
        removeOutline();
        m_texture = Texture::standard;
    }
}

bool Option::redOutline(std::string fileName, int number)
{
    if (m_text.getOutlineColor() != sf::Color::Red)
    {
        m_text.setOutlineColor(sf::Color::Red);
        m_text.setOutlineThickness(1);
        m_texture = Texture::hover;
        
        return false;
    }
    else
    {
        std::ifstream file{ "Lists/" + fileName + ".txt", std::ios::app };
        
        std::string str{ "" };
        std::string copy{ "" };

        while (std::getline(file, str))
        {
            copy += str;
            copy += '\n';

            if (str == "#")
                break;

        }

        while (std::getline(file, str))
        {
            if (str == std::to_string(number))
                continue;
            
            copy += str;
            copy += '\n';

        }

        file.close();
        std::ofstream oFile{ "Lists/" + fileName + ".txt" };
        oFile << copy;

        removeOutline();
        m_texture = Texture::standard;

        return true;
    }
        
}

void Option::setMessage(std::string_view message)
{
    std::stringstream ss;
    ss << message;
    m_text.setString(ss.str());
}

void Option::setMessage(const char message)
{
    m_text.setString(m_text.getString() + message);
}

void Option::setNumber(int number)
{
    m_number.setString(std::to_string(number) + "-");
}

void Option::setPosition(int sizeX, int sizeY, int proportion, int position)
{
    float x = sizeX / 7.f;
    float y = (static_cast<float>(sizeY) / proportion) * position;
    m_number.setPosition(sf::Vector2f(x - 50, y + 3));
    m_text.setPosition(sf::Vector2f(x, y));
}

void Option::renderText(sf::RenderWindow& window)
{
    window.draw(m_text);
    if (m_number.getString() != "-1")
        window.draw(m_number);
}

bool Option::isHovering(const sf::Vector2f& mousePos)
{
    return (m_text.getGlobalBounds().contains(mousePos)) || (m_number.getGlobalBounds().contains(mousePos));
}

int Option::size()
{
    return m_text.getString().getSize();
}

std::string Option::getString()
{
    return m_text.getString();
}

