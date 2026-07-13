#ifndef GAMES_H
#define GAMES_H
#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "assetManager.h"
#include "../states/state.h"
#include "../states/StateGame.h"

class Games {
private:
    int m_width;
    int m_height;
    sf::RenderWindow window;
    std::unique_ptr<IState> currentState;

public:
    Games(int w, int h) : m_width(w), m_height(h) {
        window.create(sf::VideoMode(sf::Vector2u(m_width, m_height)), "State Engine Pong");
        window.setFramerateLimit(60);
        currentState = std::make_unique<StateGame>(m_width, m_height);
    }

    void run() {
        while (window.isOpen()) {
            while (const std::optional event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>())
                    window.close();
            }
            if (currentState) currentState->handleInput();
            if (currentState) currentState->update();
            window.clear(sf::Color::Black);
            if (currentState) currentState->draw(window);
            window.display();
        }
    }

    void init(std::unique_ptr<IState> state) {
        currentState = std::move(state);
    }
};

#endif