#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class AssetManager {
    private:
    sf::Font font;
    sf::Shader ballShader;
    sf::SoundBuffer soundBuffer;
public:
    AssetManager() {
        if (!font.openFromFile("behance.otf")) {
            std::cerr << "Erreur : Impossible de charger la police 'behance.otf'." << std::endl;
        }
        loadSound();
        loadShaders();
    }
    const sf::Font& getFont() const {
        return font;
    }

    void loadSound() {
        if (!soundBuffer.loadFromFile("button.ogg")) {
            std::cerr << "Erreur : Impossible de charger le fichier audio 'button.ogg'." << std::endl;
        }
    }
    const sf::SoundBuffer& getSoundBuffer() const {
        return soundBuffer;
    }

    void loadShaders() {
        if (!ballShader.loadFromFile("ball.frag", sf::Shader::Type::Fragment)) {
            std::cerr << "Erreur : Impossible de charger le shader 'ball.frag'." << std::endl;
        }
    }
        const sf::Shader& getBallShader() const {
            return ballShader;
        }


    AssetManager(const AssetManager&) = delete;
    AssetManager& operator=(const AssetManager&) = delete;
    static AssetManager& getInstance() {
        static AssetManager instance;
        return instance;
    }
    
    
};

#endif