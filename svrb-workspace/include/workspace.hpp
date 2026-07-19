#ifndef WORKSPACE_HPP
#define WORKSPACE_HPP


#include "editor.hpp"
#include "terminal.hpp"
#include "filemanager.hpp"
#include "svrb_runner.hpp"



class Workspace
{

public:


    Editor editor;

    Terminal terminal;

    FileManager files;

    SVRBRunner runner;


    std::string current;



    void open(
        std::string file
    );



    void run();



};


#endif
