#pragma once
#include "../entities/Ball.h"
#include "../systems/PhysicsSystem.h"

class ScoreSystem {
private:
    inline static int playerScore = 0;
    inline static int aiScore = 0;
    inline static const int winScore = 7;

public:
    void Score(Ball& ball, int scrWidth, int scrHeight, PhysicsSystem& physics) {
        if (ball.x + ball.radius >= scrWidth) {
            ScoreSystem::aiScore++;
            physics.restart(ball, scrWidth, scrHeight);
            int redirection = (rand() % 2 == 0) ? 1 : -1;
            ball.speedx = redirection * 7;
        }
        else if (ball.x - ball.radius <= 0) {
            ScoreSystem::playerScore++;
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
        return playerScore >= winScore || aiScore >= winScore;
    }

    static int getPlayerScore() {
        return playerScore;
    }

    static int getAIScore() {
        return aiScore;
    }
};