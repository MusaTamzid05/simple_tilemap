#include "app.h"
#include <iostream>

namespace TileMap {
    App::App(int width, int height, const std::string& window_name):
        width(width),
        height(height),
        m_running(false),
        m_window(sf::VideoMode(width, height), window_name) {


    }

    void App::run() {
        m_running = m_window.isOpen();
        sf::Event m_event;

        while(m_running) {
            handle_event(m_event);
            render();

        }
    }

    void App::handle_event(sf::Event& event) {

        while(m_window.pollEvent(event)) {
            if(event.type == sf::Event::EventType::Closed) {
                std::cout << "Quiting the app.\n";
                m_running = false;
            }
        }

    }


    void App::render() {
        m_window.clear();
        m_window.display();
    }
}
