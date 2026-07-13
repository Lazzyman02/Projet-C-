#ifndef AICONTROLLER_H
#define AICONTROLLER_H

#include "../entities/Paddle.h"
#include "../entities/Ball.h"
#include "ScoreSystem.h"
#include "PhysicsSystem.h"

class AIController {
    private:
    int speed = 6.8;
public:
    void update(Paddle& aiPaddle, float ballY, PhysicsSystem& physics, int scrHeight) {
        if (ballY > aiPaddle.y) {
            aiPaddle.y += speed;
            if(ScoreSystem::getPlayerScore() >= 3) {
                speed = 7;
            }else if(ScoreSystem::getPlayerScore() >= 5) {
                speed = 7.5;
            }
        }
        if (ballY < aiPaddle.y) {
            aiPaddle.y -= speed;
            if(ScoreSystem::getPlayerScore() >= 3) {
                speed = 7;
            }else if(ScoreSystem::getPlayerScore() >= 5) {
                speed = 7.5;
            }
        }
        physics.restrictPaddle(aiPaddle, scrHeight);
    }
};

#endif