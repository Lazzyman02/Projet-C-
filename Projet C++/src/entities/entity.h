#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
public:
    int speedx = 0;
    int speedy = 0;
    int speed = 0;
    float x = 0.f;
    float y = 0.f;
    sf::Color color = sf::Color::White;

    virtual ~Entity() = default;
};

#endif