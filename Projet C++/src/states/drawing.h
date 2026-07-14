#ifndef DRAWING_H
#define DRAWING_H

#include <SFML/Graphics.hpp>
#include "../entities/Ball.h"
#include "../entities/Paddle.h"

class Drawing {
private:
    int m_width;
    int m_height;
    sf::Color yllw = sf::Color(243, 213, 91, 255);

public:
    Drawing(int width = 0, int height = 0) 
        : m_width(width), m_height(height) {}


    void initBall(Ball& ball) {
        ball.radius = 20;
        ball.x = m_width / 2.f;
        ball.y = m_height / 2.f;
        ball.color = yllw;
        ball.speedx = 7;
        ball.speedy = 7;
    }

    void initPlayerPaddle(Paddle& playerPaddle) {
        playerPaddle.width = 20.f;
        playerPaddle.height = 110.f;
        playerPaddle.color = sf::Color::Blue;
        playerPaddle.x = m_width - 30.f;
        playerPaddle.y = m_height / 2.f;
        playerPaddle.speed = 7;
    }

    void initAiPaddle(Paddle& aiPaddle) {
        aiPaddle.height = 110.f;
        aiPaddle.width = 20.f;
        aiPaddle.color = sf::Color::Red;
        aiPaddle.x = 30.f;
        aiPaddle.y = m_height / 2.f;
    }

    void initLine(sf::RectangleShape& centerLine) {
        centerLine.setSize({2.f, static_cast<float>(m_height)});
        centerLine.setFillColor(sf::Color::White);
        centerLine.setOrigin({1.f, m_height / 2.f});
        centerLine.setPosition({m_width / 2.f, m_height / 2.f});
    }

    void initPlayerScoreText(sf::Text& text) {
        text.setCharacterSize(30);
        text.setFillColor(sf::Color::White);
        text.setPosition({m_width * 3.f / 4.f, 20.f});
        text.setString("0");
    }

    void initAiScoreText(sf::Text& text) {
        text.setCharacterSize(30);
        text.setFillColor(sf::Color::White);
        text.setPosition({m_width / 4.f, 20.f});
        text.setString("0");
    }

    void initGameOverText(sf::Text& text) {
        text.setCharacterSize(40);
        text.setFillColor(sf::Color(58, 31, 97, 255));
        text.setPosition({m_width / 2.f - 140.f, m_height / 2.f - 20.f});
        text.setString("");
    }
};

#endif