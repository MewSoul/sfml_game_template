
#ifndef SFML_IMGUI_TEMPLATE_RENDERER_H
#define SFML_IMGUI_TEMPLATE_RENDERER_H

#include "flecs.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/VideoMode.hpp"

#include "Clock.h"

const int gWindowWidth {1080};
const int gWindowHeight {720};
const std::string gWindowTitle {"Template"};

class Renderer {
public:
    explicit Renderer(const flecs::world& world);

    struct WindowComponent;

private:
    sf::RenderWindow mWindow {sf::VideoMode{gWindowWidth, gWindowHeight}, gWindowTitle, sf::Style::Close};

    static void iUpdateSystem(flecs::iter it, Clock::ClockComponent* pClockComponent, Renderer::WindowComponent* pWindowComponent);
    static void iPostUpdateSystem(flecs::iter it, Clock::ClockComponent* pClockComponent);
    static void iDrawSystem(flecs::iter it, Renderer::WindowComponent* pWindowComponent);
};

struct Renderer::WindowComponent {
    sf::RenderWindow* mWindow;
};


#endif //SFML_IMGUI_TEMPLATE_RENDERER_H
