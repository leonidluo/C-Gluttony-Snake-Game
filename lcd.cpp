#include "lcd.hpp"



//构造函数
Lcd::Lcd()
{
	this ->lcd_fd = ::open("/dev/fb0",O_RDWR);
	if(-1 == this ->lcd_fd)//打开这个驱动失败了
		throw std::runtime_error("open lcd error");

	//映射
	this ->plcd = static_cast<unsigned int *>(::mmap(nullptr,
							800 * 480 * 4,
							PROT_READ | PROT_WRITE,
							MAP_SHARED,
							this ->lcd_fd,
							0));	
	if(MAP_FAILED == this ->plcd)
		throw std::runtime_error("mmap lcd error");

}

Lcd& Lcd:: GetLcd()
{
	static Lcd p;//这种我们叫饿汉式 这种模式是随着我们的进程
				//的启动就存在的，在这个工程里面有可能一次都用不到
				//因此可能会浪费资源
	return p;
	
	/*
	if(ptr == nullptr)//多线程不安全  懒汉式
		ptr = new people;
	return ptr;*/
}

//画点函数
void Lcd::Display(int x,int y,unsigned int color)
{
	if(x >= 0 && x < 800 && y >= 0 && y < 480)
		*(this ->
plcd + 800 * y + x) = color;


}


//画一个方块
void Lcd::DisplayRect(int w,int h,unsigned int color,int x0,int y0)
{
	for(int y = 0;y < h;y++)//画面
	{
		for(int x = 0;x < w;x++)//画线
		{
			this ->Display(x + x0,y + y0,color);
		}
	}
}

/*
void Lcd::DisplayTrig(int w,int h,unsigned int color,int x0,int y0,int dir)
{
	if(dir==1)
	{
		for()
	}
	for(int y = 0;y < h;y++)//画面
	{
		for(int x = 0;x < w;x++)//画线
		{
			this ->Display(x + x0,y + y0,color);
		}
	}
}
*/
unsigned int Lcd:: readcolor(int x,int y)
{
	return *(this ->plcd + 800 * y + x);
}


Lcd::~Lcd()
{
	munmap(this ->plcd,800 * 480 * 4);//解除映射
	close(this ->lcd_fd);//关闭文件描述符
}










//  snake::snake(int len,int tx,int ty,unsigned int color)
// {
	
// 	for(int x = -10 ; x <= 10;x++)
// 		for(int y = -10 ; y <= 10;y++)
// 			lcd.Display(x + tx,y + ty, color);
// 	for(int x = len ; x >=0 ; x--)
// 		for(int y=-5;y<=5;y++)
// 		lcd.Display(tx-x,ty+y, color);
// 	this -> headx = tx;
// 	this -> heady = ty;
// 	this -> endx = tx-len;
// 	this -> endy = ty;
// 	this -> len =len;
// }

// void snake::snakerun(unsigned int color)
// {

// 	//清除头部
// 	for(int x = 0 ; x <= 20;x++)
// 		for(int y = -10 ; y <= 10;y++)
// 			lcd.Display(x + headx,y + heady, 0xffffff);
// 	//
// 	for(int x = 0 ; x <= 10;x++)
// 		for(int y = -5 ; y <= 5;y++)
// 			lcd.Display(x + headx,y + heady, color);
// 	if(headx>799)headx=0;
// 	if(heady>479)heady=0;
	
// 	headx+=10;
// 	//显示头部
// 	for(int x = 0 ; x <= 20;x++)
// 		for(int y = -10 ; y <= 10;y++)
// 			lcd.Display(x + headx,y + heady, color);
// 	for(int x = 0 ; x <= 10;x++)
// 		for(int y = -5 ; y <= 5;y++)
// 			lcd.Display(x + endx,y + endy, 0xffffff);
// 	//寻找尾部位置
// 	endx+=10;
// 	if(endx>=799)endx=0;

// }	

// snake::~snake()
// {

// }









// void Lcd::  game(int cz,int sd,int xx,int yy)
// {
	
// 	Lcd & lc = Lcd::GetLcd();

// 	if(cz<=0||cz>5)return ;
	

	


// }
