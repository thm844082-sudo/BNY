#include "../include/editor.hpp"



void Editor::newLine()
{

    std::string right =
    lines[cursorY].substr(
        cursorX
    );


    lines[cursorY].erase(
        cursorX
    );


    lines.insert(
        lines.begin()+cursorY+1,
        right
    );


    cursorY++;

    cursorX=0;

}



void Editor::backspace()
{

    if(cursorX>0)
    {

        lines[cursorY].erase(
            cursorX-1,
            1
        );


        cursorX--;

    }

    else if(cursorY>0)
    {

        cursorX =
        lines[cursorY-1].size();


        lines[cursorY-1]
        +=
        lines[cursorY];


        lines.erase(
            lines.begin()+cursorY
        );


        cursorY--;

    }

}



void Editor::deleteChar()
{

    if(
        cursorX <
        lines[cursorY].size()
    )
    {

        lines[cursorY].erase(
            cursorX,
            1
        );

    }

}
