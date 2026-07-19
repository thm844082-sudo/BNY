#include "../include/parser.hpp"



std::vector<Instruction> Parser::parse(
    std::vector<std::string> lines
)
{

    std::vector<Instruction> output;


    int lineNumber=1;



    for(
        auto line:
        lines
    )
    {


        if(
            line.empty()
        )
        {
            lineNumber++;
            continue;
        }



        Instruction inst;



        size_t pos =
        line.find("(");



        if(
            pos != std::string::npos
        )
        {

            inst.signal =
            line.substr(
                0,
                pos
            );



            size_t end =
            line.find(
                ")"
            );



            inst.argument =
            line.substr(
                pos+1,
                end-pos-1
            );

        }

        else
        {

            inst.signal=line;

            inst.argument="";

        }



        inst.line=lineNumber;



        output.push_back(
            inst
        );


        lineNumber++;

    }



    return output;

}
