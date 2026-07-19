#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <string>
#include <vector>


class FileManager
{

public:

    std::vector<std::string> files;


    std::string currentFile;


    void scan(
        std::string path
    );


    bool load(
        std::string file,
        std::vector<std::string>& buffer
    );


    bool save(
        std::vector<std::string>& buffer
    );


};


#endif
