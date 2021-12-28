#ifndef TILE_MANAGER_H
#define TILE_MANAGER_H
#include <string>

namespace sf {
    class Texture;
    class Sprite;
    class RenderWindow;
};

namespace TileMap {
    struct TileManager {
        TileManager(const std::string& path = "");
        ~TileManager();

        void render(sf::RenderWindow& window);



        sf::Texture* m_texture;
        sf::Sprite* m_sprite;

    };
}

#endif
