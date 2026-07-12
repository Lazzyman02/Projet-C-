#include "src/core/games.h"

const int width = 1280;
const int height = 800;

int main() {
    Games game(width, height);
    game.run();
    return 0;
}