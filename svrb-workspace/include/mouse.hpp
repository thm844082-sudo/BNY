#ifndef MOUSE_HPP
#define MOUSE_HPP


#include <ncurses.h>


class Mouse
{

public:

    int x;
    int y;


    bool clicked;


    void update(
        MEVENT event
    );


};


#endif
