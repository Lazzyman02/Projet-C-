#include <SFML/Graphics.hpp>
#include <iostream>

class FontManager {
public:
    FontManager() {
        if (!font.loadFromFile("behance.otf")) {
            std::cerr << "Erreur : Impossible de charger la police 'behance.otf'." << std::endl;
        }
    }
    const sf::Font& getFont() const {
        return font;
    }
}