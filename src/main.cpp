#define FPS 30
#define HEIGHT 683
#define WIDTH 960
#define WINDOWTITLE "A Way Out"
#define MUSIC_PATH "../assets/music.ogg"
#define MUSIC_VOLUME 0

#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
#include "screens/screens.h"

using namespace sf;

int main() {
    //sf::Music music;
    //music.setVolume(MUSIC_VOLUME);

    //if (!music.openFromFile(MUSIC_PATH))
    //    return -1; // erreur

    //music.play();
    int screen = 0;

    VideoMode videoMode = VideoMode(WIDTH, HEIGHT, sf::Style::Fullscreen);
    RenderWindow App(videoMode, WINDOWTITLE, sf::Style::Titlebar | sf::Style::Close);
    App.setFramerateLimit(FPS);
    Player p1("rached");
    std::vector<cScreen *> Screens;

    mainMenuScreen mainMenu(p1);
    scene1Screen scene1(p1);
    scene2Screen scene2(p1);
    scene3Screen scene3(p1);
    scene4Screen scene4(p1);

    Screens.push_back(&mainMenu);
    Screens.push_back(&scene1);
    Screens.push_back(&scene2);
    Screens.push_back(&scene3);
    Screens.push_back(&scene4);

    while (screen >= 0)
        screen = Screens[screen]->Run(App);

    return 0;
}
