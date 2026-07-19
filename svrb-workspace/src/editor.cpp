#include "../include/editor.hpp"


Editor::Editor()
{

    lines.push_back("");

    cursorX=0;
    cursorY=0;

    scroll=0;

}



void Editor::init(
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



void Editor::insertText(
    char c
)
{

    lines[cursorY].insert(
        cursorX,
        1,
        c
    );


    cursorX++;

}



void Editor::input(
    int key
)
{

    if(key >= 32 && key <=126)
    {

        insertText(
            key
        );

    }



    else if(key=='\t')
    {

        lines[cursorY].insert(
            cursorX,
            "    "
        );


        cursorX+=4;

    }



    else if(key==KEY_LEFT)
    {

        if(cursorX>0)
            cursorX--;

    }



    else if(key==KEY_RIGHT)
    {

        if(cursorX < lines[cursorY].size())
            cursorX++;

    }



    else if(key==KEY_UP)
    {

        if(cursorY>0)
            cursorY--;

    }



    else if(key==KEY_DOWN)
    {

        if(cursorY < lines.size()-1)
            cursorY++;

    }



    if(cursorY-scroll >= getmaxy(window.handle)-3)
        scroll++;


    if(cursorY<scroll)
        scroll--;

}



void Editor::draw()
{

    window.clear();


    box(
        window.handle,
        0,
        0
    );


    int y=1;


    for(
        int i=scroll;
        i<lines.size();
        i++
    )
    {

        if(y >= getmaxy(window.handle)-1)
            break;


        mvwprintw(
            window.handle,
            y,
            1,
            "%03d | %s",
            i+1,
            lines[i].c_str()
        );


        y++;

    }



    wmove(
        window.handle,
        cursorY-scroll+1,
        cursorX+7
    );


    window.refresh();

}


void Editor::handleInput(int key)
{
    input(key);
}




