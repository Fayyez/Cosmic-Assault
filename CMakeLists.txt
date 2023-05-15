cmake_minimum_required(VERSION 3.0)
project(COSMIC-ASSAULT)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "/usr/include/SFML/cmake/Modules")
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(COSMIC-ASSAULT ${SOURCES})

target_link_libraries(COSMIC-ASSAULT sfml-system sfml-window sfml-graphics sfml-audio)