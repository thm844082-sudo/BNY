#ifndef PARSER_HPP
#define PARSER_HPP


#include <string>
#include <vector>


struct Instruction
{

    std::string signal;

    std::string argument;

    int line;

};



class Parser
{

public:


    std::vector<Instruction> parse(
        std::vector<std::string> lines
    );


};


#endif
