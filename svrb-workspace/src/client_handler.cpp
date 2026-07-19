#include "../include/client_handler.hpp"

#include <unistd.h>
#include <sys/socket.h>



ClientHandler::ClientHandler(
    int fd
)
{

    client_fd=fd;

}



std::string ClientHandler::receive()
{

    char buffer[1024];


    int size =
    recv(
        client_fd,
        buffer,
        sizeof(buffer)-1,
        0
    );


    if(size <= 0)
    {
        return "";
    }


    buffer[size]='\0';


    return std::string(buffer);

}



bool ClientHandler::sendMessage(
    std::string message
)
{

    int result =
    send(
        client_fd,
        message.c_str(),
        message.size(),
        0
    );


    return result >= 0;

}



void ClientHandler::closeClient()
{

    if(client_fd>=0)
    {

        close(
            client_fd
        );

    }

}
