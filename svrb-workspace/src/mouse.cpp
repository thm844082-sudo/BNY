#include "../include/mouse.hpp"


void Mouse::update(MEVENT event)
{

    x = event.x;

    y = event.y;


    clicked = true;


}
