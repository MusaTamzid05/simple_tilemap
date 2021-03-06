#include "tile_manager.h"
#include <iostream>

#include <SFML/Graphics.hpp>

namespace TileMap {
    TileManager::TileManager(const std::string& path){
        if(path == "")
            return;

        m_texture = new sf::Texture();

        if(!m_texture->loadFromFile(path)) {
            std::cerr << "Could not load " << path << "\n";
            exit(1);
        }

            
        std::cout << "texture is loaded.\n";
        m_sprite = new sf::Sprite(*m_texture);
    }


    TileManager::~TileManager() {
        delete m_sprite;
        delete m_texture;
    }

    void TileManager::render(sf::RenderWindow& window) {
        window.draw(*m_sprite);
    }

}
