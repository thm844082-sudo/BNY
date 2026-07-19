#include "../include/file_creator.hpp"

#include <fstream>


bool FileCreator::create(
    std::string path,
    std::string name
)
{

    if(
        name.find(".svrb")
        ==
        std::string::npos
    )
    {
        name += ".svrb";
    }



    std::ofstream file(
        path + "/" + name
    );


    if(!file)
        return false;



    file
    <<
    "# SVRB Program\n";


    file.close();


    return true;

}
