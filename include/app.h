#ifndef APP_H
#define APP_H

#include <string>

#include <SFML/Graphics.hpp>


namespace TileMap {
    struct TileManager;

    struct App {
        App(
            int width = 640,
            int height = 480, const std::string& window_name = "Window"
                );
        virtual ~App();

        void run();

        void handle_event(sf::Event& event);
        void render();

        void take_screenshot() const;


        int width;
        int height;
        bool m_running;

        sf::RenderWindow m_window;
        TileManager* m_tile_manager;


    };
}
#endif
