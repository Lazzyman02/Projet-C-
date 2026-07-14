#pragma once
#include "../entities/Ball.h"
#include "../systems/PhysicsSystem.h"
#include <cstdlib>

class ScoreSystem {
private:
    inline static int playerScore = 0;
    inline static int aiScore = 0;
    inline static const int winScore = 7;

    inline static int playerSets = 0;
    inline static int aiSets = 0;
    inline static const int winSets = 3; 

    void checkSetProgression() {
        if (playerScore >= winScore) {
            playerSets++;
            playerScore = 0;
            aiScore = 0;
        } 
        else if (aiScore >= winScore) {
            aiSets++;
            playerScore = 0;
            aiScore = 0;
        }
    }

public:
    void Score(Ball& ball, int scrWidth, int scrHeight, PhysicsSystem& physics) {
        if (ball.x + ball.radius >= scrWidth) {
            ScoreSystem::aiScore++;
            checkSetProgression();
            physics.restart(ball, scrWidth, scrHeight);
            int redirection = (rand() % 2 == 0) ? 1 : -1;
            ball.speedx = redirection * 7;
        }
        else if (ball.x - ball.radius <= 0) {
            ScoreSystem::playerScore++;
            checkSetProgression();
            physics.restart(ball, scrWidth, scrHeight);
            int redirection = (rand() % 2 == 0) ? 1 : -1;
            ball.speedx = redirection * 7;
        }

        if (isGameOver()) {
            ball.speedx = 0;
            ball.speedy = 0;
        }
    }

    static bool isGameOver() {
        return playerSets >= winSets || aiSets >= winSets;
    }

    static int getPlayerScore() {
        return playerScore;
    }

    static int getAIScore() {
        return aiScore;
    }

    static int getPlayerSets() {
        return playerSets;
    }

    static int getAISets() {
        return aiSets;
    }
};