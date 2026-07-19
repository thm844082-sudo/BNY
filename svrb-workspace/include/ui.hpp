#ifndef UI_HPP
#define UI_HPP

#include <ncurses.h>


class UI
{

public:

    void init();

    void shutdown();


    void box(
        int y,
        int x,
        int h,
        int w
    );


    void draw();


};


#endif
