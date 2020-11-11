#define FPS 60
#define HEIGHT 1080
#define WIDTH 1920
#define WINDOWTITLE "CLoFan"
#define FONT_PATH "../assets/LiberationSerif-Regular.ttf"

#include <SFML/Graphics.hpp>
#include "ui/menu.h"

using namespace sf;

int main() {
    VideoMode videoMode = VideoMode(WIDTH, HEIGHT);
    RenderWindow window(videoMode, WINDOWTITLE);
    window.setFramerateLimit(FPS);
    mainMenu(window);

    return 0;
}