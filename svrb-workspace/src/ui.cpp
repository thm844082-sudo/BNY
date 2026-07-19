#include "../include/ui.hpp"



void UI::init()
{

    initscr();

    noecho();

    curs_set(1);


    keypad(
        stdscr,
        TRUE
    );


    start_color();


    init_pair(
        1,
        COLOR_CYAN,
        COLOR_BLACK
    );


    init_pair(
        2,
        COLOR_GREEN,
        COLOR_BLACK
    );


    init_pair(
        3,
        COLOR_YELLOW,
        COLOR_BLACK
    );

}



void UI::shutdown()
{
    endwin();
}



void UI::box(
    int y,
    int x,
    int h,
    int w
)
{

    mvaddch(y,x,'+');
    mvaddch(y+h,x,'+');

    mvaddch(y,x+w,'+');
    mvaddch(y+h,x+w,'+');


    for(int i=1;i<w;i++)
    {
        mvaddch(y,x+i,'-');
        mvaddch(y+h,x+i,'-');
    }


    for(int i=1;i<h;i++)
    {
        mvaddch(y+i,x,'|');
        mvaddch(y+i,x+w,'|');
    }

}



void UI::draw()
{

    clear();


    int w = COLS;
    int h = LINES;



    attron(COLOR_PAIR(1));


    box(
        0,
        0,
        h-1,
        w-1
    );


    mvprintw(
        1,
        3,
        "SVRB Workspace v0.9"
    );


    attroff(COLOR_PAIR(1));



    /*
        Toolbar
    */

    mvprintw(
        1,
        30,
        "[F5 RUN] [SHIFT+F5 STOP] [CTRL+S SAVE]"
    );



    /*
        Explorer
    */

    int explorerWidth = 22;


    box(
        3,
        1,
        h-10,
        explorerWidth
    );


    attron(COLOR_PAIR(3));


    mvprintw(
        4,
        3,
        "FILES"
    );


    attroff(COLOR_PAIR(3));



    /*
        Editor
    */

    box(
        3,
        explorerWidth+2,
        h-10,
        w-explorerWidth-4
    );


    attron(COLOR_PAIR(3));


    mvprintw(
        4,
        explorerWidth+4,
        "EDITOR"
    );


    attroff(COLOR_PAIR(3));



    /*
        Output
    */

    box(
        h-6,
        1,
        4,
        w-3
    );


    attron(COLOR_PAIR(2));


    mvprintw(
        h-5,
        3,
        "OUTPUT"
    );


    attroff(COLOR_PAIR(2));



    refresh();

}
