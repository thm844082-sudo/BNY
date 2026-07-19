#include "../include/error.hpp"



RuntimeError::RuntimeError(
    std::string msg,
    int ln
)
{

    message=msg;

    line=ln;

}



std::string RuntimeError::display()
{

    return
    "[SVRB ERROR] " 
    + message
    +
    " (line "
    +
    std::to_string(line)
    +
    ")";

}
