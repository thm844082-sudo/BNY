#ifndef RUNTIME_HPP
#define RUNTIME_HPP

#include <string>


class Runtime
{

public:

    bool running;


    Runtime();


    void run();

    void stop();


    std::string status;


};


#endif
