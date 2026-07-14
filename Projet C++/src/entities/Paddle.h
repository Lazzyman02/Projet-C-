#ifndef PADDLE_H
#define PADDLE_H

#include "entity.h"

class Paddle : public Entity {
public:
    float width = 0.f;
    float height = 0.f;
    int speed = 0;

    void thePaddle(sf::RenderWindow& window) {
        sf::RectangleShape rect(sf::Vector2f(width, height));
        rect.setFillColor(color);
        rect.setOrigin(sf::Vector2f(width / 2.f, height / 2.f));
        rect.setPosition(sf::Vector2f(x, y));
        window.draw(rect);
    }

    void theWall(sf::RenderWindow& window) {
        sf::RectangleShape rect(sf::Vector2f(width, height));
        rect.setFillColor(color);
        rect.setOrigin(sf::Vector2f(width / 2.f, height / 2.f));
        rect.setPosition(sf::Vector2f(x, y));
        window.draw(rect);
    }
    
};

#endif