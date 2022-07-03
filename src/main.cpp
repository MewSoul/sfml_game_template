#include "flecs.h"
#include "imgui.h"
#include "imgui-SFML.h"

#include "Tracy.hpp"

#include "Clock.h"
#include "Input.h"
#include "Renderer.h"

int main() {
    flecs::world world;
    world.set<flecs::Rest>({});
    flecs::log::set_level(0);

    Clock clock {world};
    Renderer renderer {world};

    Input::Init(world);

    while (world.progress(clock.GetElapsedTimeSeconds())) {
        FrameMark
    }

    return EXIT_SUCCESS;
}
