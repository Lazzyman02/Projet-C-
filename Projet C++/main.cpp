#include <SFML/Graphics.hpp>
#include <iostream>
const int width = 1280;
const int height = 800;


class Ball{
    public:
    float x, y;
    int speedx, speedy;
    int radius;
    sf::Color color;
    void theBall(sf::RenderWindow& window){
        sf::CircleShape circle(radius);
        circle.setFillColor(color);
        circle.setOrigin(sf::Vector2f(radius, radius));
        circle.setPosition(sf::Vector2f(x, y));
        window.draw(circle);
    }
    void mvmnt(){
        x+=speedx;
        y+=speedy;
        if(y+radius>=height || y-radius<0){
            speedy*=-1;
        }
        if(x+radius>=width || x-radius<0){
            speedx*=-1;
        }
    }
};

class Paddle{
    protected:
    void mvmntLimit(){

        if(y+height/2.f>=::height){
            y= ::height-height/2.f;
        }
        if(y-height/2.f<=0){
            y= height/2.f;
        }
    };

    public:
    float x, y;
    float width, height;
    sf::Color color;
    int speed;

    void thePaddle(sf::RenderWindow& window){
        sf::RectangleShape paddle(sf::Vector2f(width, height));
        paddle.setFillColor(color);
        paddle.setOrigin(sf::Vector2f(width/2.f, height/2.f));
        paddle.setPosition(sf::Vector2f(x, y));
        window.draw(paddle);
    }

    void paddleMvmnt(){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
            y-=speed;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
            y+=speed;
        }
        mvmntLimit();
    };

};

class Aipaddle: public Paddle{
    
    public :
    
    void aimvmnt(float bally){
        if(bally>y){
            y+=speed;
        }
        if(bally<y){
            y-=speed;
        }
        mvmntLimit();

    }
};

Ball ball;
Paddle paddle;
Aipaddle aipddl;

int main(){
    ball.radius = 20;
    ball.x=width/2.f;
    ball.y=height/2.f;
    ball.color=sf::Color::Green;
    ball.speedx = 7;
    ball.speedy = 7;

    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(width, height)), "SFML Window");
    window.setFramerateLimit(60);
    
    //left paddle
    aipddl.height = 110.f;
    aipddl.width = 20;
    aipddl.color = sf::Color::Red;
    aipddl.y=height/2.f;
    aipddl.x=30.f;
    aipddl.speed = 7;

    sf::RectangleShape line(sf::Vector2f(2.f, height));
    line.setFillColor(sf::Color::White);
    line.setOrigin(sf::Vector2f(line.getSize().x/2.f, line.getSize().y/2.f));
    line.setPosition(sf::Vector2f(width/2.f, height/2.f));

    //right paddle
    paddle.width = 20.f;
    paddle.height = 110.f;
    paddle.color=sf::Color::Blue;
    paddle.x = width - 30.f;
    paddle.y = height/2.f;
    paddle.speed=7;

    while (window.isOpen()){
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        
        ball.mvmnt();
        paddle.paddleMvmnt();
        aipddl.aimvmnt(ball.y);

        window.clear(sf::Color::Black);
        window.draw(line);
        ball.theBall(window);
        paddle.thePaddle(window);
        aipddl.thePaddle(window);
        window.display();
    }
    return 0;
}