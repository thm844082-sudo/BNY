#ifndef PROJECT_HPP
#define PROJECT_HPP

#include <vector>
#include <string>


class Project
{

public:

    std::vector<std::string> files;

    int selected;


    void load(std::string path);

    void draw(int y,int x);


};


#endif
