#include "../include/socket_server.hpp"
#include "../include/client_handler.hpp"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>



SocketServer::SocketServer()
{

    socket_fd=-1;

    port=0;

    running=false;

}



bool SocketServer::start(
    int p
)
{

    port=p;


    socket_fd =
    socket(
        AF_INET,
        SOCK_STREAM,
        0
    );


    if(socket_fd < 0)
    {
        return false;
    }



    sockaddr_in address{};


    address.sin_family =
    AF_INET;


    address.sin_addr.s_addr =
    INADDR_ANY;


    address.sin_port =
    htons(port);



    if(
        bind(
            socket_fd,
            (sockaddr*)&address,
            sizeof(address)
        )
        < 0
    )
    {

        close(socket_fd);

        return false;

    }



    listen(
        socket_fd,
        5
    );


    running=true;


    return true;

}



bool SocketServer::acceptClient()
{

    if(!running)
    {
        return false;
    }



    int client =
    accept(
        socket_fd,
        nullptr,
        nullptr
    );



    if(client < 0)
    {
        return false;
    }



    clients.push_back(
        ClientHandler(
            client
        )
    );


    return true;

}



void SocketServer::stop()
{

    if(socket_fd >= 0)
    {

        close(
            socket_fd
        );

    }


    running=false;

}
