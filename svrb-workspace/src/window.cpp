#include "../include/window.hpp"


Window::Window()
{
    handle=nullptr;
}



void Window::create(
    int y,
    int x,
    int h,
    int w
)
{

    handle = newwin(
        h,
        w,
        y,
        x
    );


    box(
        handle,
        0,
        0
    );

}



void Window::clear()
{

    werase(handle);

}



void Window::refresh()
{

    wrefresh(handle);

}
