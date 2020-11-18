#define FPS 30
#define HEIGHT 683
#define WIDTH 960
#define WINDOWTITLE "A Way Out"
#define MUSIC_PATH "../assets/smash-bros-brawl-8-bit.ogg"
#define MUSIC_VOLUME 5

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "screens/screens.h"

using namespace sf;

int main() {
    sf::Music music;
    music.setVolume(MUSIC_VOLUME);

    if (!music.openFromFile(MUSIC_PATH))
        return -1; // erreur

    int screen = 0;

    VideoMode videoMode = VideoMode(WIDTH, HEIGHT, sf::Style::Fullscreen);
    RenderWindow App(videoMode, WINDOWTITLE, sf::Style::Titlebar | sf::Style::Close);
    App.setFramerateLimit(FPS);
    Player player;
    std::vector<baseScreen *> Screens;

    mainMenuScreen mainMenu(player);
    scene1Screen scene1(player);
    scene2Screen scene2(player);
    scene3Screen scene3(player);
    scene4Screen scene4(player);
    gameOver gameOver(player);

    Screens.push_back(&mainMenu);
    Screens.push_back(&scene1);
    Screens.push_back(&scene2);
    Screens.push_back(&scene4);
    Screens.push_back(&scene3);
    Screens.push_back(&gameOver);

    music.setLoop(true);
    music.play();

    while (screen >= 0)
        screen = Screens[screen]->Run(App);

    return 0;
}
