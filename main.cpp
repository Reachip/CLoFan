#define FPS 30
#define HEIGHT 600
#define WIDTH 1058
#define WINDOWTITLE "CLoFan"
#define MUSIC_PATH "./assets/music.ogg"
#define MUSIC_VOLUME 0
#define PLAYER_SPRIT_PATH "./assets/fumiko.png"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "screens/screens.h"
#include "game/player.h"

using namespace sf;

int main() {
    sf::Music music;
    music.setVolume(MUSIC_VOLUME);

    if (!music.openFromFile(MUSIC_PATH))
        return -1; // erreur

    music.play();
    int screen = 0;

    VideoMode videoMode = VideoMode(WIDTH, HEIGHT, sf::Style::Fullscreen);
    RenderWindow App(videoMode, WINDOWTITLE);
    App.setFramerateLimit(FPS);

    Player p1("rached", PLAYER_SPRIT_PATH);
    std::vector<cScreen *> Screens;

    mainMenuScreen mainMenu(p1);
    gameBeginningScreen gameBeginning(p1);
    scene1Screen scene1;

    Screens.push_back(&mainMenu);
    Screens.push_back(&gameBeginning);
    Screens.push_back(&scene1);

    while (screen >= 0)
        screen = Screens[screen]->Run(App);

    return 0;
}
