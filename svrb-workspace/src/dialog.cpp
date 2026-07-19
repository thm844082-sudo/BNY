#include "../include/dialog.hpp"

#include <ncurses.h>


std::string Dialog::input(
    std::string title
)
{

    echo();


    curs_set(1);


    char buffer[128];


    clear();


    mvprintw(
        5,
        5,
        "%s",
        title.c_str()
    );


    mvprintw(
        7,
        5,
        "> "
    );


    getnstr(
        buffer,
        127
    );


    noecho();


    curs_set(0);


    return std::string(buffer);

}
