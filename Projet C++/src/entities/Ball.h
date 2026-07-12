#ifndef BALL_H
#define BALL_H

#include "entity.h"

class Ball : public Entity {
public:
    int radius = 0;

    void theBall(sf::RenderWindow& window) {
        sf::CircleShape circle(static_cast<float>(radius));
        circle.setFillColor(color);
        circle.setOrigin(sf::Vector2f(static_cast<float>(radius), static_cast<float>(radius)));
        circle.setPosition(sf::Vector2f(x, y));
        window.draw(circle);
    }
};

#endif