#ifndef STATEGAME_H
#define STATEGAME_H

#include "state.h"
#include "../entities/Ball.h"
#include "../entities/Paddle.h"
#include "../systems/PhysicsSystem.h"
#include "../systems/AIController.h"
#include "../systems/ScoreSystem.h"
#include "../core/assetManager.h"
#include "drawing.h"
#include <string>

class StateGame : public IState
{
private:
    int m_width, m_height;
    sf::Color drkgrn = sf::Color(20, 160, 133, 255);

    // Game Entities
    Ball ball;
    Paddle playerPaddle;
    Paddle aiPaddle;

    ScoreSystem score;
    PhysicsSystem physics;
    AIController aiC;
    Drawing drawHelper; 
    sf::RectangleShape centerLine;

    sf::Text playerScoreText;
    sf::Text aiScoreText;
    sf::Text gameOverText;
    bool gameOver = false;

public:
    StateGame(int scrWidth, int scrHeight)
        : m_width(scrWidth),
          m_height(scrHeight),
          drawHelper(scrWidth, scrHeight),
          playerScoreText(AssetManager::getInstance().getFont()),
          aiScoreText(AssetManager::getInstance().getFont()),
          gameOverText(AssetManager::getInstance().getFont())
    {
        drawHelper.initBall(ball);
        drawHelper.initPlayerPaddle(playerPaddle);
        drawHelper.initAiPaddle(aiPaddle);
        drawHelper.initLine(centerLine);

        drawHelper.initPlayerScoreText(playerScoreText);
        drawHelper.initAiScoreText(aiScoreText);
        drawHelper.initGameOverText(gameOverText);
    }

    void handleInput() override
    {
        if (gameOver) return;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
            playerPaddle.y -= playerPaddle.speed;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
            playerPaddle.y += playerPaddle.speed;
    }

    void update() override
    {
        if (gameOver) return;

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

        window.clear(drkgrn);
        window.draw(centerLine);
        playerPaddle.thePaddle(window);
        aiPaddle.thePaddle(window);
        ball.theBall(window);
        window.draw(playerScoreText);
        window.draw(aiScoreText);

        if (gameOver) {
            window.draw(gameOverText);
        }
    }
};

#endif