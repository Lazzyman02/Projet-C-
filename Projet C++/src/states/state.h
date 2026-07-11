#include <SFML/Graphics.hpp>
#include <iostream>
class WindowManager {
public:
    WindowManager() : window(sf::VideoMode(sf::Vector2u(800, 600)), "Mon Jeu de Ping Pong !") {
        window.setFramerateLimit(60);
    }
    sf::RenderWindow& getWindow() {
        return window;
    }
}