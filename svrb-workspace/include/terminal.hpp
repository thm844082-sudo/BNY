#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include <string>
#include <vector>

#include "window.hpp"


class Terminal
{

public:

    Terminal();


    Window window;


    std::vector<std::string> history;


    int scroll;


    void init(
        int y,
        int x,
        int h,
        int w
    );


    void write(
        std::string text
    );


    void draw();


};


#endif
