
#include "snake.hpp"

int fg=0;
Snake:: Snake()
{
	
	for(int i=0;i<150;i+=10)
	{
		snakeDrawBody(400+i,240,1);
		Snake :: pos.push(std::make_pair(400+i,240));
	}
}

Snake & Snake :: GetSnake()
{
	static Snake p;
	return p;
	
	
}


int Snake :: snakerun(int dir,int step)
{
	if(dir<=0||dir>5)return 0;
	
    int headx,heady,endx,endy;
	unsigned int foodcolor = 0xe81224,color,helppos;
	std::pair<int,int> headpos,endpos;
	//传位置
	headpos=Snake::pos.back();
	endpos=Snake::pos.front();
	
	
	headx=headpos.first;
	heady=headpos.second;

	endx=endpos.first;
	endy=endpos.second;
	
	
	snakeDrawEye(headx,heady,0);


	//前进判断
	if(dir==1)
	{
		heady-=step;
		if(heady<=4)heady=479;
		color=snakelcd.readcolor(headx,heady-5);
		helppos=snakelcd.readcolor(headx+9,heady-5);
        if(color > 0x1000000)
            color%=0x1000000;
        //printf("%X  %d %X\n", color, color==0x000000, 0xffffff);
		if(color==0x66ccff||color==0x000000)
		{
            printf("%d %d\n", headx, heady-5);
			return 1;
		}
		else if(color==foodcolor||helppos==foodcolor)
		{
			fg=4;
		}
		
	}
	else if(dir==2)
	{
		heady+=step;
		if(heady>=474)heady=0;

		color=snakelcd.readcolor(headx,heady+5);
		helppos=snakelcd.readcolor(headx+9,heady+5);
        if(color > 0x1000000)
            color%=0x1000000;
		if(color==0x66ccff||color==0x000000)
		{
			return 1;
		}
		else if(color==foodcolor||helppos==foodcolor)
		{
			fg=4;
		}
	}
	
	else if(dir==4)
	{
		headx-=step;
		if(headx<=4)headx=799;


		color=snakelcd.readcolor(headx-5,heady);
		helppos=snakelcd.readcolor(headx-5,heady+9);
        if(color > 0x1000000)
            color%=0x1000000;
		if(color==0x66ccff||color==0x000000)
		{
			return 1;
		}
		else if(color==foodcolor||helppos==foodcolor)
		{
			fg=4;
		}
	}
	else if(dir==3)
	{
		headx+=step;
		if(headx>=794)headx=0;

		
		color=snakelcd.readcolor(headx+5,heady);
		helppos=snakelcd.readcolor(headx+5,heady+9);
        if(color > 0x1000000)
            color%=0x1000000;
		if(color==0x66ccff||color==0x000000)
		{
			return 1;
		}
		else if(color==foodcolor||helppos==foodcolor)
		{
			fg=4;
		}
	}
	
	if(fg<=0)
	{
		pos.pop();
		snakeDrawBody(endx,endy,0);//清除尾部
	}
	else
	{
		if(fg==4)
		{
            games.addScore();
			std::cout<<"eat!"<<std::endl;
			mouse.Eat_food();
			mouse.Appear_food();
		}
		
		if(fg<=3)
		{
			std::cout<<"eat!"<<std::endl;
		}
		fg--;
		
	}
	snakeDrawBody(headx,heady,1);
	snakeDrawEye(headx,heady,1);
	Snake :: pos.push(std::make_pair(headx,heady));
	
	return 0;
}


void Snake :: snakeDrawBody(int xx,int yy,int fg1)
{
	if(fg1==1)
	snakelcd.DisplayRect(10,10,0x66ccff,xx,yy);
	else 
	snakelcd.DisplayRect(10,10,0xffffff,xx,yy);
}

//void Snake :: snakeDrawTail(int xx,int yy,int fg,int dx,int dy)


void Snake :: snakeDrawEye(int xx,int yy,int fg1)
{
	if(fg1==1)
	snakelcd.DisplayRect(3,3,0x000000,xx+3,yy+3);
	else 
	snakelcd.DisplayRect(3,3,0x66ccff,xx+3,yy+3);
}



Snake:: ~Snake()
{
	
}
