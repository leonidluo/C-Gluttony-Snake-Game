#include <iostream>
#include "touchev.hpp"
#include "lcd.hpp"
#include <chrono>
#include <thread>
#include "Snake.hpp"
#include <stdio.h>

#include "runthread.hpp"
#include "music.hpp"
#include "bmp.hpp"
//外部声明
extern Direction dir;

using namespace std::chrono_literals;
void musicRun() {
    Music& music = Music::getInstance();
    music.playMusic();
}



int main()
{
	try
	{
		Lcd & lcd = Lcd::GetLcd();
        std::thread th2{Touchfunc};
		Music& music = Music::getInstance();

        BmpClass bcss;//图片类

        bcss.Display("10.bmp",0,0);
        while(dir == Direction::DirErr) {

        }

		bcss.Display("1.bmp",0,0);

		std::this_thread::sleep_for(2000ms);




        std::thread th1(musicRun);

		std::thread th3{Lcdfunc};
		while(1);


	}
	catch(const std::runtime_error & w)
	{
		std::cout << "system error:" <<w.what();
		perror(" ");
	}

	return 0;
}










