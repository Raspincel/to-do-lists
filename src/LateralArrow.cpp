#include "LateralArrow.h"

void LateralArrow::setArrow()
{
    // the arrow is composed of 8 coordinates
    if (m_side == Direction::right)
    {
        m_arrow[0].position = sf::Vector2f(screenSize::x - 14.f, screenSize::y / 2);
        m_arrow[1].position = sf::Vector2f(screenSize::x - 30.f, screenSize::y / 2 - 16);
        m_arrow[2].position = sf::Vector2f(screenSize::x - 30.f, screenSize::y / 2 - 3);
        m_arrow[3].position = sf::Vector2f(screenSize::x - 50.f, screenSize::y / 2 - 3);
        m_arrow[4].position = sf::Vector2f(screenSize::x - 50.f, screenSize::y / 2 + 3);
        m_arrow[5].position = sf::Vector2f(screenSize::x - 30.f, screenSize::y / 2 + 3);
        m_arrow[6].position = sf::Vector2f(screenSize::x - 30.f, screenSize::y / 2 + 16);
        m_arrow[7].position = sf::Vector2f(screenSize::x - 14.f, screenSize::y / 2);
    }
    else
    {
        m_arrow[0].position = sf::Vector2f(14.f, screenSize::y / 2);
        m_arrow[1].position = sf::Vector2f(30.f, screenSize::y / 2 - 16);
        m_arrow[2].position = sf::Vector2f(30.f, screenSize::y / 2 - 3);
        m_arrow[3].position = sf::Vector2f(50.f, screenSize::y / 2 - 3);
        m_arrow[4].position = sf::Vector2f(50.f, screenSize::y / 2 + 3);
        m_arrow[5].position = sf::Vector2f(30.f, screenSize::y / 2 + 3);
        m_arrow[6].position = sf::Vector2f(30.f, screenSize::y / 2 + 16);
        m_arrow[7].position = sf::Vector2f(14.f, screenSize::y / 2);
    }

    m_arrow[0].color = sf::Color::White;
    setStandardTexture();
}

void LateralArrow::setStandardTexture()
{
    if (!m_texture.loadFromFile("Images/metal.jpg")) // random image
        std::cerr << "Failure in loading texture\n";
}

void LateralArrow::setHoverTexture()
{
    if (!m_texture.loadFromFile("Images/cactus.jpg")) // random image
        std::cerr << "Failure in loading texture\n";
}

void LateralArrow::setTextCoords()
{
    // determines from which part of the texture image the arrow grabs its texture
    m_arrow[0].texCoords = sf::Vector2f(14.f, 25.f);
    m_arrow[1].texCoords = sf::Vector2f(30.f, 9.f);
    m_arrow[2].texCoords = sf::Vector2f(30.f, 22.f);
    m_arrow[3].texCoords = sf::Vector2f(50.f, 22.f);
    m_arrow[4].texCoords = sf::Vector2f(50.f, 28.f);
    m_arrow[5].texCoords = sf::Vector2f(30.f, 28.f);
    m_arrow[6].texCoords = sf::Vector2f(30.f, 41.f);
    m_arrow[7].texCoords = sf::Vector2f(14.f, 25.f);
}

void LateralArrow::arrowInteraction()
{
    hovering(true); // why does this exist?
}