#include "../include/ui.hpp"
#include "../include/editor.hpp"
#include "../include/project.hpp"
#include "../include/output.hpp"
#include "../include/runner.hpp"


int main()
{

    UI ui;

    Editor editor;

    Project project;

    Output output;

    Runner runner;



    ui.init();



    project.load(
        "svrb/examples"
    );



    keypad(
        stdscr,
        TRUE
    );



    int key;



    while(true)
    {

        ui.draw();


        project.draw(
            5,
            5
        );


        editor.draw();


        output.draw();



        refresh();



        key=getch();



        /*
            F5 RUN
        */

        if(key==KEY_F(5))
        {

            runner.execute(
                output
            );

        }



        /*
            F4 EXIT
        */

        if(key==KEY_F(4))
        {
            break;
        }



        /*
            Editor input
        */

        if(
            key!=KEY_F(5)
            &&
            key!=KEY_F(4)
        )
        {

            editor.handleInput(
                key
            );

        }


    }



    ui.shutdown();


    return 0;

}
