
#include "Input.h"

#include "imgui-SFML.h"
#include "SFML/Window/Event.hpp"

#include "Renderer.h"

void InputSystem(flecs::iter it, Renderer::WindowComponent* pWindowComponent) {
    sf::Event event {};

    auto* pWindow = pWindowComponent->mWindow;
    while (pWindow->pollEvent(event))
    {
        ImGui::SFML::ProcessEvent(event);

        if (event.type == sf::Event::Closed ||
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
        {
            it.world().quit();
        }
    }
}

void Input::Init(const flecs::world& world) {
    world.system<Renderer::WindowComponent>("InputSystemPreUpdate")
            .kind(EcsPreUpdate)
            .arg(1)
            .singleton()
            .iter(InputSystem);
}