#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H

#include "../entities/Ball.h"
#include "../entities/Paddle.h"

class PhysicsSystem {
private:
    void updateBall(Ball& ball, int scrWidth, int scrHeight) {
        ball.x += ball.speedx;
        ball.y += ball.speedy;


        if (ball.y + ball.radius >= scrHeight || ball.y - ball.radius < 0) {
            ball.speedy *= -1;
        }
        if (ball.x + ball.radius >= scrWidth || ball.x - ball.radius < 0) {
            ball.speedx *= -1;
        }
    }

    void restrictPaddle(Paddle& paddle, int scrHeight) {
        if (paddle.y + paddle.height / 2.f >= scrHeight) {
            paddle.y = scrHeight - paddle.height / 2.f;
        }
        if (paddle.y - paddle.height / 2.f <= 0) {
            paddle.y = paddle.height / 2.f;
        }
    }
};

#endif