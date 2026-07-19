#ifndef EDITOR_HPP
#define EDITOR_HPP


#include <vector>
#include <string>

#include "window.hpp"


class Editor
{

public:

    Editor();


    Window window;


    std::vector<std::string> lines;


    int cursorX;

    int cursorY;

    int scroll;



    void init(
        int y,
        int x,
        int h,
        int w
    );



    void draw();



    void input(
        int key
    );


    // Compatibility with old main.cpp
    void handleInput(
        int key
    );



    void insertText(
        char c
    );


    void newLine();


    void backspace();


    void deleteChar();


};


#endif
