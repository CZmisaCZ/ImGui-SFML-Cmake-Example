#include <iostream>
#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imgui-SFML.h"
#include "imgui_internal.h"

int main(int, char**) {
    std::cout << "Hello, world!\n";

    //create SFML window 
    sf::RenderWindow window;
    window.create(sf::VideoMode(800, 600), "Example window", sf::Style::Close);
    window.display();

    //initiate SFML-imgui
    ImGui::SFML::Init(window);
    
    sf::Clock update_clock;
    sf::Event event;

    //main loop
    while (window.isOpen()) {
        
        //process events and update
        ImGui::SFML::Update(window, update_clock.restart());
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        ImGui::SFML::ProcessEvent(event);

        //create simple window
        ImGui::Begin("Test Window");
        ImGui::Text("sample text");
        ImGui::Button("Button test");
        ImGui::End();

        //render
        window.clear();
        ImGui::SFML::Render(window);
        window.display();
    }
    
    ImGui::SFML::Shutdown();
}
