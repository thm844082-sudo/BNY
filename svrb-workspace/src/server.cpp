#include "../include/server.hpp"



Server::Server()
{

    running=false;

    port=0;

}



bool Server::start(
    int p
)
{

    port=p;

    running=true;


    return true;

}



void Server::stop()
{

    running=false;


    clients.clear();

}



void Server::addClient(
    std::string name
)
{

    clients.push_back(
        name
    );

}



int Server::clientCount()
{

    return clients.size();

}
