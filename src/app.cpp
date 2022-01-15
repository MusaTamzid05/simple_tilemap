#include "app.h"
#include <iostream>

#include "tile_manager.h"

namespace TileMap {
    App::App(int width, int height, const std::string& window_name):
        width(width),
        height(height),
        m_running(false),
        m_window(sf::VideoMode(width, height), window_name) {
            m_tile_manager = new TileManager("../resources/tile_set_1.png");
            screenshot_path = "test.jpg";


    }

    App::~App() {
    }


    void App::run() {
        m_running = m_window.isOpen();
        sf::Event m_event;

        while(m_running) {
            handle_event(m_event);
            render();
        }


        take_screenshot();
        close_window();


    }

    void App::handle_event(sf::Event& event) {

        while(m_window.pollEvent(event)) {
            if(event.type == sf::Event::EventType::Closed) {
                m_running = false;
            }
            else if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Escape)
                    m_running = false;

            }
        }

    }


    void App::render() {
        m_window.clear();
        m_tile_manager->render(m_window);
        m_window.display();
    }


    void App::take_screenshot() const {
        sf::Texture texture;
        texture.create(m_window.getSize().x, m_window.getSize().y);
        texture.update(m_window);

        sf::Image screenshot_image = texture.copyToImage();


        if(!screenshot_image.saveToFile(screenshot_path)) {
            std::cerr << "Could not save image.\n";
        }


    }

    void App::close_window() {
        delete m_tile_manager;
        m_window.close();

    }
}
