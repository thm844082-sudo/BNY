#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <vector>
#include <string>


class Output
{

public:

    std::vector<std::string> lines;

    int scroll;


    Output();


    void add(
        std::string text
    );


    void draw();


};


#endif
