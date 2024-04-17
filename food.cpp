//
// Created by Administrator on 2023/6/12.
//
#include "food.hpp"



Food::Food() {

    //srand((unsigned)time(NULL));

        this->x=(rand()%(200-100+1))+100;
        this->y=(rand()%(200-100+1))+100;
        cout <<"x:"<< x << '\t' <<endl;
        cout << "y:"<< y << '\t' <<endl;
        lcd.DisplayRect(15,15,0xe81224,x, y);

}

void Food::Appear_food() {


    //srand((unsigned)time(NULL));

    this->x=(rand()%(770-30+1))+30;
    this->y=(rand()%(450-30+1))+30;
    while(lcd.readcolor(x,y) == 0x66ccff || lcd.readcolor(x,y)%1000000 == 0x000000){
        this->x=(rand()%(800-0+1))+0;
        this->y=(rand()%(480-0+1))+0;

    }
    cout <<"x:"<< x << '\t' <<endl;
    cout << "y:"<< y << '\t' <<endl;


    
    lcd.DisplayRect(15, 15, 0xe81224, this->x, this->y);
}

void Food::Eat_food()
{

    lcd.DisplayRect(15,15,0xffffff,this->x,this->y);

}

int Food::getX() {
    return x;
}

int Food::getY() {
    return y;
}








