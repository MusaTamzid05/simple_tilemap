#ifndef APP_H
#define APP_H

#include <string>

#include <SFML/Graphics.hpp>

namespace TileMap {
    struct App {
        App(
            int width = 640,
            int height = 480, const std::string& window_name = "Window"
                );
        virtual ~App() {}

        void run();

        void handle_event(sf::Event& event);
        void render();


        int width;
        int height;
        bool m_running;

        sf::RenderWindow m_window;


    };
}
#endif
