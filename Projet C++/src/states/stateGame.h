#ifndef STATEGAME_H
#define STATEGAME_H

#include "state.h"
#include "../entities/Ball.h"
#include "../entities/Paddle.h"
#include "../systems/PhysicsSystem.h"
#include "../systems/AIController.h"
#include "../systems/ScoreSystem.h"
#include "../core/assetManager.h"
#include <string>

class StateGame : public IState
{
private:
    int m_width, m_height;

    Ball ball;
    Paddle playerPaddle;
    Paddle aiPaddle;

    ScoreSystem score;
    PhysicsSystem physics;
    AIController aiC;

    sf::RectangleShape centerLine;

    sf::Text playerScoreText;
    sf::Text aiScoreText;
    sf::Text gameOverText;
    bool gameOver = false;

public:
    StateGame(int scrWidth, int scrHeight)
        : m_width(scrWidth),
          m_height(scrHeight),
          playerScoreText(AssetManager::getInstance().getFont()),
          aiScoreText(AssetManager::getInstance().getFont()),
          gameOverText(AssetManager::getInstance().getFont())
    {

        ball.radius = 20;
        ball.x = m_width / 2.f;
        ball.y = m_height / 2.f;
        ball.color = sf::Color::Green;
        ball.speedx = 7;
        ball.speedy = 7;

        aiPaddle.height = 110.f;
        aiPaddle.width = 20.f;
        aiPaddle.color = sf::Color::Red;
        aiPaddle.x = 30.f;
        aiPaddle.y = m_height / 2.f;

        playerPaddle.width = 20.f;
        playerPaddle.height = 110.f;
        playerPaddle.color = sf::Color::Blue;
        playerPaddle.x = m_width - 30.f;
        playerPaddle.y = m_height / 2.f;
        playerPaddle.speed = 7;

        centerLine.setSize({2.f, static_cast<float>(m_height)});
        centerLine.setFillColor(sf::Color::White);
        centerLine.setOrigin({1.f, m_height / 2.f});
        centerLine.setPosition({m_width / 2.f, m_height / 2.f});

        playerScoreText.setCharacterSize(30);
        playerScoreText.setFillColor(sf::Color::White);
        playerScoreText.setPosition({m_width * 3.f / 4.f, 20.f});
        playerScoreText.setString("0");

        aiScoreText.setCharacterSize(30);
        aiScoreText.setFillColor(sf::Color::White);
        aiScoreText.setPosition({m_width / 4.f, 20.f});
        aiScoreText.setString("0");

        gameOverText.setCharacterSize(40);
        gameOverText.setFillColor(sf::Color::Yellow);
        gameOverText.setPosition({m_width / 2.f - 140.f, m_height / 2.f - 20.f});
        gameOverText.setString("");
    }

    void handleInput() override
    {
        if (gameOver) {
            return;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            playerPaddle.y -= playerPaddle.speed;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            playerPaddle.y += playerPaddle.speed;
    }

    void update() override
    {
        if (gameOver) {
            return;
        }

        physics.updateBall(ball, m_width, m_height);
        score.Score(ball, m_width, m_height, physics);
        playerScoreText.setString(std::to_string(ScoreSystem::getPlayerScore()));
        aiScoreText.setString(std::to_string(ScoreSystem::getAIScore()));

        if (ScoreSystem::isGameOver()) {
            gameOver = true;
            gameOverText.setString(ScoreSystem::getPlayerScore() >= 5 ? "Player Wins!" : "AI Wins!");
            return;
        }

        physics.restrictPaddle(playerPaddle, m_height);
        physics.collision(ball, playerPaddle);
        physics.collision(ball, aiPaddle);
        aiC.update(aiPaddle, ball.y, physics, m_height);
    }

    void draw(sf::RenderWindow& window) override
    {
        window.draw(centerLine);

        ball.theBall(window);
        playerPaddle.thePaddle(window);
        aiPaddle.thePaddle(window);
        window.draw(playerScoreText);
        window.draw(aiScoreText);

        if (gameOver) {
            window.draw(gameOverText);
        }
    }
};

#endif