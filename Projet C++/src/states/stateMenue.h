#include <SFML/Graphics.hpp>
#include <iostream>
#include "ui/HUD.h"
class MenuState {
    public:
        MenuState(sf::RenderWindow& window) : window(window), fontManager() {
            if (!fontManager.getFont().getInfo().family.empty()) {
                menuTitle.setFont(fontManager.getFont());
                optionPVP.setFont(fontManager.getFont());
                optionPVE.setFont(fontManager.getFont());
            } else {
                std::cerr << "Erreur : Police non chargée. Affichage du menu sans texte." << std::endl;
            }
        }

        void draw() {
            window.clear();
            window.draw(menuTitle);
            window.draw(optionPVP);
            window.draw(optionPVE);
            window.display();
        }
}