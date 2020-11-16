cmake_minimum_required(VERSION 3.7)
project(Game)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/game/player.cpp src/game/player.h src/ui/button.cpp src/ui/button.h src/screens/cScreen.h src/screens/mainMenuScreen.cpp src/screens/mainMenuScreen.h src/screens/gameBeginningScreen.cpp src/screens/gameBeginningScreen.h src/screens/screens.h src/screens/scene1Screen.cpp src/screens/scene1Screen.h src/screens/cScreen.cpp src/game/door.cpp src/game/door.h src/game/entitie.cpp src/game/entitie.h src/game/entities.h src/game/background.cpp src/game/background.h src/ui/messageBox.cpp src/ui/messageBox.h src/game/pnj.cpp src/game/pnj.h src/screens/scene2Screen.cpp src/screens/scene2Screen.h src/screens/scene3Screen.cpp src/screens/scene3Screen.h)
add_executable(Game ${SOURCE_FILES})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system graphics window network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif ()
