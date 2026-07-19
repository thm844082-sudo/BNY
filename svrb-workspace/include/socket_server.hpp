#ifndef SOCKET_SERVER_HPP
#define SOCKET_SERVER_HPP


#include <vector>

#include "client_handler.hpp"



class SocketServer
{

public:


    int socket_fd;

    int port;


    bool running;



    std::vector<ClientHandler> clients;



    SocketServer();



    bool start(
        int port
    );



    bool acceptClient();



    void stop();


};


#endif
