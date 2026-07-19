#include "../include/explorer.hpp"



void Explorer::init(
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


    selected=0;

}



void Explorer::draw()
{

    window.clear();


    box(
        window.handle,
        0,
        0
    );



    int y=1;


    for(
        int i=0;
        i<files.size();
        i++
    )
    {

        if(i==selected)
        {

            wattron(
                window.handle,
                A_REVERSE
            );

        }


        mvwprintw(
            window.handle,
            y++,
            1,
            "%s",
            files[i].c_str()
        );



        if(i==selected)
        {

            wattroff(
                window.handle,
                A_REVERSE
            );

        }

    }



    window.refresh();

}



void Explorer::click(
    int y
)
{

    int index=y-1;


    if(
        index>=0 &&
        index<files.size()
    )
    {

        selected=index;

    }

}



std::string Explorer::current()
{

    if(files.empty())
        return "";


    return files[selected];

}
