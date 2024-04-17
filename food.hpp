//
// Created by Administrator on 2023/6/12.
//

#ifndef TOUCH_FOOD_HPP
#define TOUCH_FOOD_HPP

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "lcd.hpp"

using namespace std;

class Food
{
   int x,y;
   Lcd & lcd = Lcd::GetLcd();
public:
   Food();
   void Appear_food();
   void Eat_food();
   int getX();
   int getY();



};


#endif //TOUCH_FOOD_HPP
