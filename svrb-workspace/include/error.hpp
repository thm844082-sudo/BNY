#ifndef ERROR_HPP
#define ERROR_HPP


#include <string>


class RuntimeError
{

public:

    std::string message;

    int line;


    RuntimeError(
        std::string msg,
        int ln
    );


    std::string display();


};


#endif
