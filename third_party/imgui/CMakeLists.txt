cmake_minimum_required(VERSION 3.21)
project(imgui) # Dear ImGui version 1.88

add_library(imgui STATIC
        imgui/imgui.cpp imgui/imgui_draw.cpp imgui/imgui_tables.cpp imgui/imgui_widgets.cpp imgui/misc/cpp/imgui_stdlib.cpp
        imgui/imgui-SFML.cpp # From: https://github.com/eliasdaler/imgui-sfml, added so imgui can work with SFML
        imgui/imgui_demo.cpp # To remove for releases
        )

target_include_directories(imgui PUBLIC imgui)
target_link_libraries(imgui ${CMAKE_DL_LIBS} sfml-graphics)