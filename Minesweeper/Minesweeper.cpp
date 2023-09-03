#include <SFML/Graphics.hpp>
#include <time.h>
#include "Minesweeper.h"
using namespace sf;

const int BOMB = 9;
const int EMPTY = 10;
const int FLAG = 11;
const int W = 12;
const int H = 12;

void setupGrid(int grid[12][12], int sgrid[12][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            grid[i][j] = 0;
            sgrid[i][j] = EMPTY;
        }
    }
    
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (rand() % 7 == 0) grid[i][j] = BOMB;
        }
    }

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            int n = 0;
            if (grid[i][j] == BOMB) continue;
            if (grid[i + 1][j] == BOMB) n++;
            if (grid[i][j + 1] == BOMB) n++;
            if (grid[i - 1][j] == BOMB) n++;
            if (grid[i][j - 1] == BOMB) n++;
            if (grid[i + 1][j + 1] == BOMB) n++;
            if (grid[i - 1][j - 1] == BOMB) n++;
            if (grid[i - 1][j + 1] == BOMB) n++;
            if (grid[i + 1][j - 1] == BOMB) n++;
            grid[i][j] = n;
        }
    }
}

void openEmptyCells(int x, int y) {
    
}

int main()
{
    srand(time(0));

    RenderWindow app(VideoMode(400, 400), "Minesweeper!");

    int w = 32;
    int grid[12][12];
    int viewGrid[12][12]; //for showing

    setupGrid(grid, viewGrid);

    Texture t;
    t.loadFromFile("images/tiles.jpg");
    Sprite s(t);

    while (app.isOpen()) {
        Vector2i pos = Mouse::getPosition(app);
        int x = pos.x / w;
        int y = pos.y / w;

        Event e;
        while (app.pollEvent(e)) {
            if (e.type == Event::Closed) {
                app.close();
            }
        }

        if (e.type == Event::MouseButtonPressed) {
            if (e.key.code == Mouse::Left) {
                if (grid[x][y] == 0) {

                }
                viewGrid[x][y] = grid[x][y];
            }
            else if (e.key.code == Mouse::Right) {
                viewGrid[x][y] = FLAG;
            }
        }
            
        app.clear(Color::White);

        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                s.setTextureRect(IntRect(viewGrid[i][j] * w, 0, w, w));
                s.setPosition(i * w, j * w);
                app.draw(s);
            }
        }

        app.display();
    }
    return 0;
}
