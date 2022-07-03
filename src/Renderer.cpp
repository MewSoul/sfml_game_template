
#include "Renderer.h"

#include "imgui.h"
#include "imgui-SFML.h"

Renderer::Renderer(const flecs::world& world) {
    ImGui::SFML::Init(mWindow);

    world.set<WindowComponent>({&mWindow});

    world.system<Clock::ClockComponent, Renderer::WindowComponent>("UpdateSystem")
            .kind(EcsOnUpdate)
            .arg(1)
            .singleton()
            .arg(2)
            .singleton()
            .iter(iUpdateSystem);

    world.system<Clock::ClockComponent>("PostUpdateSystem")
            .kind(EcsPostUpdate)
            .arg(1)
            .singleton()
            .iter(iPostUpdateSystem);

    world.system<Renderer::WindowComponent>("DrawSystem")
            .kind(EcsOnStore)
            .arg(1)
            .singleton()
            .iter(iDrawSystem);
}

void Renderer::iUpdateSystem(flecs::iter it, Clock::ClockComponent *pClockComponent,
                       Renderer::WindowComponent *pWindowComponent) {
    (void)it;

    ImGui::SFML::Update(*pWindowComponent->mWindow, pClockComponent->mClock->getElapsedTime());
}

void Renderer::iPostUpdateSystem(flecs::iter it, Clock::ClockComponent *pClockComponent) {
    (void)it;

    pClockComponent->mClock->restart();
}

void Renderer::iDrawSystem(flecs::iter it, Renderer::WindowComponent *pWindowComponent) {
    (void)it;

    auto* pWindow = pWindowComponent->mWindow;

    pWindow->clear();

    ImGui::ShowDemoWindow();

    ImGui::SFML::Render(*pWindow);
    pWindow->display();
}
