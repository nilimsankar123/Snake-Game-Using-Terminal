#include <iostream>
#include<windows.h> //to control cursor position in the console
#include<conio.h>
#include<ctime>
#include"Snake.h"
#include"Food.h"
#include<bits/stdc++.h>
#define HEIGHT 25
#define WIDTH 50

using namespace std;
int len1=1;

Snake snake({WIDTH/2,HEIGHT/2},1);
Food food;


void board()
{

    int length=1;
    COORD snake_pos = snake.get_pos();
    COORD food_pos=food.get_pos();
    vector<COORD> snake_body=snake.get_body();
    cout<<"\t\t\t       SNAKE GAME CREATED BY NISHANT HAZARIKA AND NILIM SANKAR BORA\n\n";

    for(int i=0;i<HEIGHT;i++)
    {

        cout<<"\t\t\t\t..";
        for(int j=0;j<WIDTH-2;j++)
        {
            if(i==0 || i==HEIGHT-1)
                cout<<".";
            else if(i==snake_pos.Y && j+1==snake_pos.X)
                cout<<"0";
            else if(i==food_pos.Y && j+1==food_pos.X)
                cout<<"*";
            else
                {
                    bool isbodypart=false;
                    for(int k=0;k<snake_body.size()-1;k++)
                    {
                        if(i==snake_body[k].Y&&j+1==snake_body[k].X)
                        {
                            cout<<'0';
                            isbodypart=true;
                            length++;
                            break;
                        }
                    }
                    if(!isbodypart)
                        cout<<' ';
                }
        }
        cout<<"..\n";
    }
    cout<<"                  SCORE IS :"<<length;

}

int main()
{
    srand(time(NULL)); //to generate food many times
    food.gen_food();   //to generate the 1st food randomly anywhere in the grid
    char game_over=false;
    while(!game_over)
    {
        board();
        if(kbhit())    //to hit the keyboard strokes
        {
            switch(getch())
            {
                case 'w':snake.change_dir('u'); break;
                case 's':snake.change_dir('d'); break;
                case 'a':snake.change_dir('l'); break;
                case 'd':snake.change_dir('r'); break;

            }
        }

            if(snake.collided())
            {
                game_over = true;

                cout<<"           GAME OVER\n";

                break;
            }

        if(snake.eaten(food.get_pos()))    //if food is eaten then generate another food
        {
            food.gen_food();
            snake.grow();
        }

             snake.move_snake();
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0}); //TO pick up the cursor from the end and to put it on the origin

    }

    return 0;
}
