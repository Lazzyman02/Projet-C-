#ifndef GAMES_H
#define GAMES_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "../states/stateGame.h"

class Games {
private:
    int width;
    int height;
    sf::RenderWindow window;

public:
    Games(int w, int h) : width(w), height(h) {
        window.create(sf::VideoMode(sf::Vector2u(width, height)), "State Engine Pong");
        window.setFramerateLimit(60);
        
    }

    void run() {
        while (window.isOpen()) {
            while (const std::optional event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>())
                    window.close();
            }

            // 1. Inputs Processing
            if (currentState) currentState->handleInput();

            // 2. State Physics Updates
            if (currentState) currentState->update();

            // 3. Frame Graphic Renderings
            window.clear(sf::Color::Black);
            if (currentState) currentState->draw(window);
            window.display();
        }
    }
};

#endif