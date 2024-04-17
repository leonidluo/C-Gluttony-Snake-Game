#ifndef __TOUCHEV_HPP__
#define __TOUCHEV_HPP__



#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <chrono>
#include <thread>	
#include <linux/input.h>			
	

enum Direction
{
	DirErr = 0x00,//错误
	DirUp,		
	DirDown,
	DirRight,
	DirLeft,
	DirClick //点击

};



//实现一个触摸屏的类

class TouchEv
{
	int ev_fd;
	
	TouchEv();
	TouchEv(const TouchEv & te);
	TouchEv & operator=(const TouchEv & p) ;
	~TouchEv();

public:
	static TouchEv &  GetTouch();
	void Run(void);

	
	
};














#endif










