#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H

#include "../entities/Ball.h"
#include "../entities/Paddle.h"
#include "../core/assetManager.h"

class PhysicsSystem {
    private:
    sf::Sound sound{AssetManager::getInstance().getSoundBuffer()};

public:
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

    void collision(Ball& ball, Paddle& paddle) {
        if (ball.x - ball.radius < paddle.x + paddle.width / 2.f &&
            ball.x + ball.radius > paddle.x - paddle.width / 2.f &&
            ball.y + ball.radius > paddle.y - paddle.height / 2.f &&
            ball.y - ball.radius < paddle.y + paddle.height / 2.f) {
            
            
            sound.setBuffer(AssetManager::getInstance().getSoundBuffer());
            sound.play();
            ball.speedx *= -1;
            ball.speedx *= 1.1f;
            ball.speedy *= 1.1f;
            
        }
    }

    void restart(Ball& ball, int scrWidth, int scrHeight) {

        ball.x = scrWidth / 2.f;
        ball.y = scrHeight / 2.f;
        ball.speedx = 7.f;
        ball.speedy = 7.f;

    }

};

#endif