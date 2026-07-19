#include "../include/output.hpp"

#include <ncurses.h>


Output::Output()
{
    scroll=0;
}



void Output::add(std::string text)
{
    lines.push_back(text);
}



void Output::draw()
{

    int y = LINES-10;


    mvprintw(
        y,
        5,
        "OUTPUT"
    );


    y++;


    for(
        int i=scroll;
        i<lines.size() && i<scroll+6;
        i++
    )
    {

        mvprintw(
            y++,
            5,
            "%s",
            lines[i].c_str()
        );

    }

}
