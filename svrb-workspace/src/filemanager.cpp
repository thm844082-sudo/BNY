#include "../include/filemanager.hpp"

#include <filesystem>
#include <fstream>


using namespace std;



void FileManager::scan(
    string path
)
{

    files.clear();


    for(
        auto &entry :
        filesystem::directory_iterator(path)
    )
    {

        if(
            entry.path().extension()
            ==
            ".svrb"
        )
        {

            files.push_back(
                entry.path().string()
            );

        }

    }

}



bool FileManager::load(
    string file,
    vector<string>& buffer
)
{

    ifstream input(file);


    if(!input)
        return false;



    buffer.clear();


    string line;


    while(
        getline(
            input,
            line
        )
    )
    {

        buffer.push_back(
            line
        );

    }



    currentFile=file;


    return true;

}



bool FileManager::save(
    vector<string>& buffer
)
{

    if(
        currentFile.empty()
    )
        return false;



    ofstream output(
        currentFile
    );


    if(!output)
        return false;



    for(
        auto &line:
        buffer
    )
    {

        output
        <<
        line
        <<
        "\n";

    }



    return true;

}
