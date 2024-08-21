#ifndef SNAKE_H //guard block (takes care of multiple iniatialization
#define SNAKE_H
#include<windows.h> // used to access the coordinate system
#include<vector>
#define HEIGHT 25
#define WIDTH 50
using namespace std;

// the features that snake should have
//position of the head , length , direction , velocity(talking about the no of characters/3 pixels at a time as an example)
class Snake
{
   private:
       COORD pos;
       int len;
       int vel;
       char direction;
       vector<COORD> body;
   public:
        Snake(COORD pos,int vel);
        void change_dir(char dir);  //method to change the direction of the snake
        void move_snake();
        vector<COORD> get_body(); //it is used to get the position of the snake
        COORD get_pos(); //to get current position of the snake;
        bool eaten(COORD food_pos);

        void grow();
        bool collided();
};

#endif // SNAKE_H
