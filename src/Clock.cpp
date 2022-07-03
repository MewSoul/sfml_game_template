
#include "Clock.h"

Clock::Clock(const flecs::world& world) {
    world.set<ClockComponent>({&mClock});
}

float Clock::GetElapsedTimeSeconds() const {
    return mClock.getElapsedTime().asSeconds();
}