#include "../include/workspace.hpp"



void Workspace::open(
    std::string file
)
{

    if(
        files.load(
            file,
            editor.lines
        )
    )
    {

        current=file;


        terminal.write(
            "[OPEN] "
            +
            file
        );


        editor.cursorX=0;

        editor.cursorY=0;

    }

    else
    {

        terminal.write(
            "[ERROR] Cannot open file"
        );

    }


}



void Workspace::run()
{

    if(
        current.empty()
    )
    {

        terminal.write(
            "[ERROR] No file selected"
        );

        return;

    }



    terminal.write(
        "[RUN] "
        +
        current
    );



    runner.run(
        editor.lines,
        terminal
    );


}
