#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <ncurses.h>


class Window
{

public:

    WINDOW* handle;


    Window();


    void create(
        int y,
        int x,
        int h,
        int w
    );


    void clear();


    void refresh();


};


#endif
