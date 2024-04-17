#include "touchev.hpp"
#include "lcd.hpp"


//int xx=200,yy=100;


Direction dir = Direction::DirErr;//方向

using namespace std::chrono_literals;



TouchEv& TouchEv:: GetTouch()
{
	static TouchEv p;
	return p;

}




TouchEv::TouchEv()
{
	//打开这个触摸屏
	this ->ev_fd = ::open("/dev/input/event0",O_RDWR);
	if(-1 == this ->ev_fd)
		throw std::runtime_error("open ev0 error");

}

TouchEv::TouchEv(const TouchEv & te)
{
	//std::cout << "复制构造" << std::endl;
	this ->ev_fd = ::open("/dev/input/event0",O_RDWR);
	if(-1 == this ->ev_fd)
		throw std::runtime_error("open ev0 error");
}




void TouchEv::Run(void)
{
	//实例化维护的对象
	struct input_event ev;
	//Lcd lc;
	//int yetx,yety;
	int i = 0;
	int ev_x,ev_y,ev_x0,ev_y0;
	while(1)
	{
		int r = ::read(this ->ev_fd,&ev,sizeof(ev));
		if(r != sizeof(ev))
		{
			//为了容错  我可以在这里实现一个超时处理
			i++;
			if(i == 10)//连续错10次还没有成功我就认为你真的有问题了
				throw std::runtime_error("read ev0 error");
			std::this_thread::sleep_for(1ms);
			continue;
			
		}
		i = 0;
		//获取坐标
		if(EV_ABS == ev.type)
		{
			if(ABS_X == ev.code)
			{
				ev_x = ev.value;
			}
			else if(ABS_Y == ev.code)
			{
				ev_y = ev.value;
			}
		}
		if(ev.code == BTN_TOUCH && ev.value == 0x01)//手刚刚按下去
		{
			ev_x0 = ev_x;
			ev_y0 = ev_y;
		}
		else if(ev.code == BTN_TOUCH && ev.value == 0x00)//手抬起来了
		{
			if(ev_x0 == ev_x && ev_y0 == ev_y)
			{
			//	dir = Direction::DirClick;
			}
			else //滑动
			{
				if(ev_x > ev_x0 && abs(ev_x - ev_x0) > abs(ev_y - ev_y0) && dir != Direction::DirLeft)
				{
					dir = Direction::DirRight;
				}
				else if(ev_x < ev_x0 && abs(ev_x - ev_x0) > abs(ev_y - ev_y0)&& dir != Direction::DirRight)
				{
					dir = Direction::DirLeft;
				}
				else if(ev_y < ev_y0 && abs(ev_x - ev_x0) < abs(ev_y - ev_y0)&& dir != Direction::DirDown)
				{
					dir = Direction::DirUp;
				}
				else if(ev_y > ev_y0 && abs(ev_x - ev_x0) < abs(ev_y - ev_y0)&& dir != Direction::DirUp)
				{
					dir = Direction::DirDown;
				}
				
			}
		}
		
	}


}


		
TouchEv::~TouchEv()
{
	close(this ->ev_fd);
}




















