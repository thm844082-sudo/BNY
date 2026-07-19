#ifndef SERVER_HPP
#define SERVER_HPP


#include <string>
#include <vector>


class Server
{

public:


    bool running;


    int port;


    std::vector<std::string> clients;



    Server();



    bool start(
        int port
    );



    void stop();



    void addClient(
        std::string name
    );



    int clientCount();


};


#endif
