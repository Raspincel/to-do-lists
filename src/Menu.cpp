#include "menu.h"

void Menu::renderMenuTexts(sf::RenderWindow& window)
{
    m_creation.renderText(window);
    m_view.renderText(window);
    m_delete.renderText(window);
}

void Menu::setTexts()
{
    m_creation.setMessage("Create List");
    m_view.setMessage("View List");
    m_delete.setMessage("Delete list");
}

void Menu::setPositions()
{
    m_creation.setPosition(screenSize::x, screenSize::y, 4, 1);
    m_view.setPosition(screenSize::x, screenSize::y, 4, 2);
    m_delete.setPosition(screenSize::x, screenSize::y, 4, 3);
}

void Menu::openCreationScreen()
{
    ScreenState::screen = Screen::creation;
};

void Menu::openViewScreen()
{
    ScreenState::screen = Screen::view;
}

void Menu::openDeleteScreen()
{
    ScreenState::screen = Screen::deleting;
}

void Menu::ifClicked(const sf::Vector2f& mousePos)
{
    if (m_creation.isHovering(mousePos))
        openCreationScreen();
    else if (m_view.isHovering(mousePos))
        openViewScreen();
    else if (m_delete.isHovering(mousePos))
        openDeleteScreen();
}

void Menu::render(const sf::Vector2f& mousePos, sf::RenderWindow& window)
{
    renderMenuTexts(window);
}

void Menu::hovering(const sf::Vector2f& mousePos)
{
    m_creation.outline(mousePos);
    m_view.outline(mousePos);
    m_delete.outline(mousePos);
}