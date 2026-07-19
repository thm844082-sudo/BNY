#ifndef SIGNAL_HPP
#define SIGNAL_HPP


#include <string>


class Signal
{

public:


    virtual std::string execute(
        std::string argument
    ) = 0;


};


#endif
