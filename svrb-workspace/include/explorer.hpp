#ifndef EXPLORER_HPP
#define EXPLORER_HPP


#include <vector>
#include <string>

#include "window.hpp"


class Explorer
{

public:


    Window window;


    std::vector<std::string> files;


    int selected;


    bool changed;



    void init(
        int y,
        int x,
        int h,
        int w
    );



    void draw();



    void click(
        int y
    );



    std::string current();



};


#endif
