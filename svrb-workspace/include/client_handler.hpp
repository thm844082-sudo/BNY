#ifndef CLIENT_HANDLER_HPP
#define CLIENT_HANDLER_HPP


#include <string>


class ClientHandler
{

public:

    int client_fd;


    ClientHandler(
        int fd
    );


    std::string receive();


    bool sendMessage(
        std::string message
    );


    void closeClient();


};


#endif
