//
// Created by 86134 on 2023/6/11.
//

#ifndef MAIN_CPP_MUSIC_HPP
#define MAIN_CPP_MUSIC_HPP
#include "touchev.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <stdio.h>
#include <atomic>

extern Direction dir;
class Music {
    int musics;
    bool fl = true;

public:
    static Music& getInstance() {
        static Music instance(1);
        return instance;
    }

    void setMusic(int music);
    void playMusic(void);

    int getMusic();
    void stopMusic();


private:
    Music(int musics) : musics(musics){};
    Music(const Music&) = delete;
    Music& operator = (const Music&) = delete;

};



#endif //MAIN_CPP_MUSIC_HPP
