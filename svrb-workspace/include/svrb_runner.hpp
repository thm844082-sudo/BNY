#ifndef SVRB_RUNNER_HPP
#define SVRB_RUNNER_HPP


#include <vector>
#include <string>

#include "terminal.hpp"


class SVRBRunner
{

public:


    void run(
        std::vector<std::string> code,
        Terminal &terminal
    );


};


#endif
