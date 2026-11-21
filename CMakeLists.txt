cmake_minimum_required(VERSION 3.16)
project(SAE1.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(SAE1.1
    main.cpp
    index.cpp
    utils/backToMenu.cpp
    utils/clearScreen.cpp
    utils/getRandomWord.cpp
    utils/getRandomNb.cpp
    minigames/pendu/pendu.cpp
    minigames/snake/snake.cpp
    minigames/wordle/wordle.cpp
    minigames/blackjack/func_blackjack.cpp
)

target_include_directories(SAE1.1 PRIVATE ${PROJECT_SOURCE_DIR})