#ifndef __SNAKE_H__
#define __SNAKE_H__



#include "lcd.hpp"
#include <utility>
#include <queue>
#include "food.hpp"
#include "game.hpp"

class Snake 
{
	
	std::queue<std::pair<int,int>> pos;
	Lcd & snakelcd = Lcd::GetLcd();
	Food mouse = Food();
    Game games = Game();
	//Food duck = Food();
	Snake();
	~Snake();
	Snake(const Snake & p) = delete;//将拷贝构造删除
	Snake & operator=(const Snake & p) = delete;

public:

	

	static Snake & GetSnake();
	int snakerun(int dir,int step);
	void snakeDrawBody(int xx,int yy,int fg = 0);
	//void snakeDrawTail(int xx,int yy,int fg = 0);
	void snakeDrawEye(int xx,int yy,int fg = 0);
	
	
};





#endif