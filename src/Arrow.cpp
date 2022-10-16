#include "Arrow.h"

void Arrow::setArrow()
{
    // the arrow is composed of 8 coordinates
    m_arrow[0].position = sf::Vector2f(14.f, 25.f);
    m_arrow[1].position = sf::Vector2f(30.f, 9.f);
    m_arrow[2].position = sf::Vector2f(30.f, 22.f);
    m_arrow[3].position = sf::Vector2f(50.f, 22.f);
    m_arrow[4].position = sf::Vector2f(50.f, 28.f);
    m_arrow[5].position = sf::Vector2f(30.f, 28.f);
    m_arrow[6].position = sf::Vector2f(30.f, 41.f);
    m_arrow[7].position = sf::Vector2f(14.f, 25.f);

    m_arrow[0].color = sf::Color::White;
    setStandardTexture();
}

void Arrow::setStandardTexture()
{
    if (!m_texture.loadFromFile("Images/metal.jpg")) // random image
        std::cerr << "Failure in loading texture\n";
}

void Arrow::setHoverTexture()
{
    if (!m_texture.loadFromFile("Images/cactus.jpg")) // random image
        std::cerr << "Failure in loading texture\n";
}

void Arrow::setTextCoords()
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


void Arrow::arrowInteraction()
{
    if (ScreenState::screen == Screen::creation)
    {
        CreationStep::state = Render::naming;
        ScreenState::screen = Screen::menu;
    }
    else if (ScreenState::screen == Screen::view)
    {
        if (ChooseView::step == Viewing::lists)
        {
            ChooseView::step = Viewing::none;
            ScreenState::screen = Screen::menu;
        }
        else
        {
            ChooseView::step = Viewing::lists;
        }
    }
    else if (ScreenState::screen == Screen::view)
    {
        ScreenState::screen = Screen::menu;
    }
    else if (ScreenState::screen == Screen::deleting)
    {
        ScreenState::screen = Screen::menu;
    }
}