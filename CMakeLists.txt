cmake_minimum_required(VERSION 3.21)
include(FetchContent)

set(PROJECT_NAME "sfml_game_template")
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-Wno-deprecated -Wall -Wextra")

FetchContent_Declare(
        flecs
        GIT_REPOSITORY https://github.com/SanderMertens/flecs
        GIT_TAG v3.0.2-beta
)
FetchContent_MakeAvailable(flecs)

set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML
        GIT_TAG 2.5.1
)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json
        GIT_TAG v3.10.5
)
FetchContent_MakeAvailable(nlohmann_json)

FetchContent_Declare(
        Tracy
        GIT_REPOSITORY https://github.com/wolfpld/tracy
        GIT_TAG v0.8.2
)
FetchContent_MakeAvailable(Tracy)

# Other Third Party Libraries
add_subdirectory(third_party/imgui) # From: https://github.com/ocornut/imgui
include_directories(third_party/cuteheaders) # From: https://github.com/RandyGaul/cute_headers

include_directories(src/core)
add_executable(${PROJECT_NAME} src/main.cpp src/core/Input.cpp src/core/Input.h src/core/Renderer.cpp src/core/Renderer.h src/core/Clock.cpp src/core/Clock.h)
target_link_libraries(${PROJECT_NAME} flecs sfml-system sfml-window sfml-graphics sfml-audio sfml-network nlohmann_json::nlohmann_json imgui TracyClient)

add_compile_options(-O2 -DTRACY_ENABLE)