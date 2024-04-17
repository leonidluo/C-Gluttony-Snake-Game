#ifndef __LCD_H__
#define __LCD_H__


#include <iostream>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <chrono>
#include <thread>


//lcd类
class Lcd
{
	private:

	int lcd_fd;//屏幕的文件描述符
	unsigned int * plcd;//映射首地址
	
	Lcd();
	~Lcd();
	Lcd(const Lcd & p) = delete;//将拷贝构造删除
	Lcd & operator=(const Lcd & p) = delete;

	public:
	
	static Lcd&  GetLcd();
	void Display(int x,int y,unsigned int color);
	void DisplayRect(int w,int h,unsigned int color = 0xffffff,int x0 = 0,int y0 = 0);
	//void game(int cz,int sd,int xx=200,int yy=100);
	unsigned int readcolor(int x,int y);

};









#endif







