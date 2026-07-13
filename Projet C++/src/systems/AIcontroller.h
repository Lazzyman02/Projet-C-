#ifndef AICONTROLLER_H
#define AICONTROLLER_H

#include "../entities/Paddle.h"
#include "../entities/Ball.h"
#include "PhysicsSystem.h"

class AIController {
    private:
    int speed = 6.8;
public:
    void update(Paddle& aiPaddle, float ballY, PhysicsSystem& physics, int scrHeight) {
        if (ballY > aiPaddle.y) {
            aiPaddle.y += speed;
        }
        if (ballY < aiPaddle.y) {
            aiPaddle.y -= speed;
        }
        physics.restrictPaddle(aiPaddle, scrHeight);
    }
};

#endif