#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
public:
    int speedx;
    int speedy;
    int speed;
    float x;
    float y;
    sf::Color color = sf::Color::White;

    virtual ~Entity() = default;
};

#endif