//
// Created by 86134 on 2023/6/11.
//

#include "music.hpp"

/**
 * playMusic需要开一个线程
 */
void Music::playMusic() {
    int a = 30;
    while(fl) {
        char buf[64];
        sprintf(buf, "madplay -Q %d.mp3", a);
        system(buf);
    }

}


void Music::stopMusic() {
    system("killall -9 madplay");
    fl = false;
}

void Music::setMusic(int musics) {
    this -> musics = musics;
}

int Music::getMusic() {
    return musics;
}

