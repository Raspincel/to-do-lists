#include <SFML/Graphics.hpp>

#include <array>
#include <iostream>
#include <string_view>

// Classes and etc
#include "Arrow.h"
#include "Creation.h"
#include "Delete.h"
#include "ListMaking.h"
#include "Menu.h"
#include "Option.h"
#include "View.h"

// Functions and variables
#include "constants.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(screenSize::x, screenSize::y), "To-do list", sf::Style::Titlebar | sf::Style::Close);

    // Screens setup
    Menu menuScreen;
    Creation creationScreen;
    Delete deleteScreen;

    View viewScreen;

    bool pauseKb{ true }; // Set pause between actions with keyboard
    bool pauseMs{ true };
    // Main loop
    while (window.isOpen())
    {
        sf::Event event;

        // Get state of the mouse in any given moment
        auto mousePixels{ sf::Mouse::getPosition(window)};
        auto mousePos{ window.mapPixelToCoords(mousePixels) };
       

        // Poll events
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
            }
            
            // guarantees a certain pause between every time a screen is pressed
            if (event.type == sf::Event::KeyPressed && pauseKb)
            {
                switch (ScreenState::screen)
                {
                case Screen::creation:
                    if (sf::Event::TextEntered)
                        pauseKb = creationScreen.writeText(mousePos); // returns false if a key is pressed
                    break;
                }
            }
            else
            {
                pauseKb = true;
            }
        }

        // stuff
                    // There's no arrow in the main menu
        if (ScreenState::screen == Screen::menu)
        {
            menuScreen.hovering(mousePos);
        }
        else if (ScreenState::screen == Screen::creation)
        {
            creationScreen.hovering(mousePos);
        }
        else if (ScreenState::screen == Screen::view)
        {
            viewScreen.hovering(mousePos);
        }
        else if (ScreenState::screen == Screen::deleting)
        {
            deleteScreen.hovering(mousePos);
        }

        if (event.type == sf::Event::MouseButtonReleased)
        {
            if (pauseMs)
            {
                pauseMs = false;

                switch (ScreenState::screen) // Some things are only done in some screens
                {
                case Screen::menu:
                    menuScreen.ifClicked(mousePos);
                    if (ScreenState::screen == Screen::view)
                    {
                        viewScreen.updateList();
                        ChooseView::step = Viewing::lists;
                    }
                    else if (ScreenState::screen == Screen::deleting)
                    {
                        deleteScreen.updateDeleting();
                    }

                    break;
                case Screen::creation:
                    creationScreen.mouseClicked(mousePos);
                    break;
                case Screen::view:
                    viewScreen.mouseClicked(mousePos);
                    break;
                case Screen::deleting:
                    deleteScreen.mouseClicked(mousePos);
                    break;
                    

                }
            }
        }
        else
            pauseMs = true;
        
        // Clears screen
        window.clear(sf::Color::Black);
        
        // Renders new screen
        switch (ScreenState::screen)
        {
        case Screen::menu:
            menuScreen.render(mousePos, window);
            break;
        case Screen::creation:
            creationScreen.render(window);
            break;
        case Screen::view:
            viewScreen.renderPage(window);
            break;
        case Screen::deleting:
            deleteScreen.renderPage(window);
        }

        // Displays new screen
        window.display();
    }

    return 0;
}
