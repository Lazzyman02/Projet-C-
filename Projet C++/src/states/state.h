#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>

class State {
public:
    virtual ~State() = default;
    virtual void handleInput() = 0;
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
};

#endif