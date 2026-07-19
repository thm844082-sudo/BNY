#include "../include/actions.hpp"

#include <fstream>



Actions::Actions(
    Workspace* ws
)
{

    workspace=ws;

}



void Actions::save()
{

    if(
        workspace->files.save(
            workspace->editor.lines
        )
    )
    {

        workspace->terminal.write(
            "[OK] File saved"
        );

    }

    else
    {

        workspace->terminal.write(
            "[ERROR] Save failed"
        );

    }

}



void Actions::newFile()
{

    std::string name =
    "untitled.svrb";



    std::ofstream file(
        name
    );


    file
    <<
    "# New SVRB Program\n";



    file.close();



    workspace->open(
        name
    );


    workspace->terminal.write(
        "[NEW] Created "
        +
        name
    );

}
