#include "Snake.h" //we don't need to define windows.h as in Snake.h we are already defining that header file

Snake::Snake(COORD pos,int vel) //constructor to the class Snake
{

    this->pos=pos;
    this->vel=vel;

    len=1;
    direction='n';
    body.push_back(pos);
}

void Snake::change_dir(char dir)
{
    direction = dir;
}
void Snake::grow()
{
    len++;
}
COORD Snake::get_pos()
{
    return pos;
}
vector<COORD> Snake::get_body()
{
    return body;
}

void Snake::move_snake()
{
    switch(direction)

    {
    case 'u': pos.Y -=vel; break;
    case 'd': pos.Y +=vel; break;
    case 'l': pos.X -=vel; break;
    case 'r': pos.X +=vel; break;
    }
    body.push_back(pos);
    if(body.size()>len)
        body.erase(body.begin());//shifting the position of head...
}


bool Snake::eaten(COORD food_pos)   //check if the food has been eaten or not
{
    if(food_pos.X == pos.X && food_pos.Y == pos.Y) return true;
    else return false;
}

bool Snake::collided()
{
    if(pos.X<1 || pos.X>WIDTH-2 || pos.Y<1 || pos.Y>HEIGHT-2) return true;
    else return false;
}
