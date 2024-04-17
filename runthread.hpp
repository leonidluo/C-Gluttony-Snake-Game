#ifndef __RUNTHREAD_H__
#define __RUNTHREAD_H__
#include "music.hpp"
#include "bmp.hpp"
extern Direction dir;

void Touchfunc()
{
	TouchEv & ev = TouchEv :: GetTouch();
	
	ev.Run();
}
void snakeDrawBody(int xx,int yy,int fg = 0);
void Lcdfunc()
{
	int endrun=0;
	Snake & user = Snake::GetSnake();
	int i=0;
	int xx=200,yy=100;
	while(1)
	{
		if(endrun==1)
		{
            BmpClass bmpClass;
            Music& music = Music::getInstance();
			std::cout<<"game over!"<<std::endl;
            music.stopMusic();
            bmpClass.Display("50.bmp", 0, 0);
            std::this_thread::sleep_for(2s);
            exit(0);
		}
		//这里就可以让我们的方块移动
		//std::cout << "i = " << i++ << "  Dir = "<< dir <<std::endl;
	
		endrun=user.snakerun(dir,5);
		std::this_thread::sleep_for(50ms);

	}




}


#endif 