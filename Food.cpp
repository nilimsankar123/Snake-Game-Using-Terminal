#include "Food.h"



//to generate a random number in the range from u to l , the formula is = rand()%upper_limit-(lowerlimit+1)+lowerLimit
void Food::gen_food()
{
    pos.X=(rand() % (WIDTH-3))+1;
    pos.Y=(rand() % (HEIGHT-3))+1;

}
//getting position
COORD Food::get_pos()
{
    return pos;
}


