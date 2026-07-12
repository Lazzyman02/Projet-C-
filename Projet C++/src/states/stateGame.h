#ifndef STATEGAME_H
#define STATEGAME_H

#include "state.h"
#include "../entities/Ball.h"
#include "../entities/Paddle.h"
#include "../systems/PhysicsSystem.h"
#include "../systems/AIController.h"

class StateGame : public State {
private:
    int width, height;
    Ball ball;
    Paddle playerPaddle;
    Paddle aiPaddle;
    
    PhysicsSystem physics;
    AIController aiC;
    sf::RectangleShape centerLine;

public:
    StateGame(int scrWidth, int scrHeight) : width(scrWidth), height(scrHeight) {
        // Initialize Ball
        ball.radius = 20;
        ball.x = width / 2.f;
        ball.y = height / 2.f;
        ball.color = sf::Color::Green;
        ball.speedx = 7;
        ball.speedy = 7;

        // Initialize Left AI Paddle
        aiPaddle.height = 110.f;
        aiPaddle.width = 20.f;
        aiPaddle.color = sf::Color::Red;
        aiPaddle.x = 30.f;
        aiPaddle.y = height / 2.f;

        // Initialize Right Player Paddle
        playerPaddle.width = 20.f;
        playerPaddle.height = 110.f;
        playerPaddle.color = sf::Color::Blue;
        playerPaddle.x = width - 30.f;
        playerPaddle.y = height / 2.f;
        playerPaddle.speed = 7;

        // Middle Divider Court Line
        centerLine.setSize(sf::Vector2f(2.f, static_cast<float>(height)));
        centerLine.setFillColor(sf::Color::White);
        centerLine.setOrigin(sf::Vector2f(1.f, height / 2.f));
        centerLine.setPosition(sf::Vector2f(width / 2.f, height / 2.f));
    }

    void handleInput() override {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
            playerPaddle.y -= playerPaddle.speed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
            playerPaddle.y += playerPaddle.speed;
        }
    }

    void update() override {
        physics.updateBall(ball, width, height);
        physics.restrictPaddle(playerPaddle, height);
        aiC.update(aiPaddle, ball.y, physics, height);
    }

    void draw(sf::RenderWindow& window) override {
        window.draw(centerLine);
        ball.theBall(window);
        playerPaddle.thePaddle(window);
        aiPaddle.thePaddle(window);
    }
};

#endif