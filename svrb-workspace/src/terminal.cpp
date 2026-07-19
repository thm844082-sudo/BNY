#include "../include/terminal.hpp"


Terminal::Terminal()
{

    scroll = 0;

}



void Terminal::init(
    int y,
    int x,
    int h,
    int w
)
{

    window.create(
        y,
        x,
        h,
        w
    );

}



void Terminal::write(
    std::string text
)
{

    history.push_back(
        text
    );


    if(history.size()>500)
    {
        history.erase(
            history.begin()
        );
    }

}



void Terminal::draw()
{

    window.clear();


    box(
        window.handle,
        0,
        0
    );


    int y=1;


    int start =
        history.size()
        -
        scroll;


    if(start < 0)
        start=0;



    for(
        int i=start;
        i<history.size();
        i++
    )
    {

        if(y >= getmaxy(window.handle)-1)
            break;


        mvwprintw(
            window.handle,
            y++,
            1,
            "%s",
            history[i].c_str()
        );

    }



    window.refresh();

}
