
#ifndef SFML_IMGUI_TEMPLATE_CLOCK_H
#define SFML_IMGUI_TEMPLATE_CLOCK_H

#include "flecs.h"
#include "SFML/System/Clock.hpp"

class Clock {
public:
    explicit Clock(const flecs::world& world);

    struct ClockComponent;

    float GetElapsedTimeSeconds() const;

private:
    sf::Clock mClock {};
};

struct Clock::ClockComponent {
    sf::Clock* mClock;
};


#endif //SFML_IMGUI_TEMPLATE_CLOCK_H
