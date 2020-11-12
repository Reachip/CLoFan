#define FPS 60
#define HEIGHT 1080
#define WIDTH 1920
#define WINDOWTITLE "CLoFan"
#define MUSIC_PATH "../assets/music.ogg"
#define MUSIC_VOLUME 2
#define PLAYER_SPRIT_PATH "../assets/sprites/people/male_spellcast.png"

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

    Player p1("rached", PLAYER_SPRIT_PATH);
    std::vector<cScreen *> Screens;

    mainMenuScreen mainMenu;
    gameBeginningScreen gameBeginning(p1);
    gameBeginningScreen gameBeginning1(p1);

    Screens.push_back(&mainMenu);
    Screens.push_back(&gameBeginning1);
    Screens.push_back(&gameBeginning);

    VideoMode videoMode = VideoMode(WIDTH, HEIGHT);
    RenderWindow App(videoMode, WINDOWTITLE);
    App.setFramerateLimit(FPS);

    while (screen >= 0)
        screen = Screens[screen]->Run(App);

    return 0;
}
