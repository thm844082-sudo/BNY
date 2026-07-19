#include "../include/project.hpp"

#include <ncurses.h>
#include <filesystem>

using namespace std;


void Project::load(string path)
{

    files.clear();


    for(auto &entry : filesystem::directory_iterator(path))
    {

        if(entry.path().extension()==".svrb")
        {
            files.push_back(
                entry.path().filename().string()
            );
        }

    }


    selected = 0;

}



void Project::draw(int y,int x)
{

    mvprintw(
        y,
        x,
        "PROJECT"
    );


    y += 2;


    for(int i=0;i<files.size();i++)
    {

        if(i==selected)
            attron(A_REVERSE);


        mvprintw(
            y+i,
            x,
            "%s",
            files[i].c_str()
        );


        if(i==selected)
            attroff(A_REVERSE);

    }

}
