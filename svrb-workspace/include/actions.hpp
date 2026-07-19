#ifndef ACTIONS_HPP
#define ACTIONS_HPP


#include "workspace.hpp"


class Actions
{

public:


    Workspace* workspace;


    Actions(
        Workspace* ws
    );


    void save();


    void newFile();


};


#endif
