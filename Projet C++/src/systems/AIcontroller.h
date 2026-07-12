#ifndef AICONTROLLER_H
#define AICONTROLLER_H

#include "../entities/Paddle.h"
#include "PhysicsSystem.h"

class AIController {
public:
    void update(Paddle& aiPaddle, float ballY, PhysicsSystem& physics, int scrHeight) {
        if (ballY > aiPaddle.y) {
            aiPaddle.y += speed;
        }
        if (ballY < aiPaddle.y) {
            aiPaddle.y -= speed;
        }
        PhysicsSystem::restrictPaddle(aiPaddle, scrHeight);
    }
};

#endif