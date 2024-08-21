#ifndef FOOD_H
#define FOOD_H
#define HEIGHT 25
#define WIDTH 50
#include"Snake.h"

#include<windows.h>   //to access the position
#include<cstdlib>  //to generate random function
class Food
{
    private:
        COORD pos;
    public:

        void gen_food();
        COORD get_pos();

};

#endif // FOOD_H
