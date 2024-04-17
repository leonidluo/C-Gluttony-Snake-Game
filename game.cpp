//
// Created by 86134 on 2023/6/14.
//

#include "game.hpp"

Game::Game() {
    score = 1;
}

void Game::addScore() {
    BmpClass bmpClass;
    Music& music = Music::getInstance();
    char buf[64];
    score++;
    sprintf(buf, "%d.bmp", score);
    bmpClass.Display(buf, 0, 0);
    if(score == 5) {
        //std::this_thread::sleep_for(2s);
        bmpClass.Display("60.bmp", 0, 0);
        music.stopMusic();
        exit(0);
    }
}