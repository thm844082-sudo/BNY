#include "../include/server.hpp"

#include <string>


Server globalServer;



std::string execute_server_signal(
    std::string signal,
    std::string argument
)
{


    if(signal=="0xD0")
    {

        globalServer.start(
            std::stoi(argument)
        );


        return
        "Server started on port "
        +
        argument;

    }



    if(signal=="0xD1")
    {

        globalServer.addClient(
            argument
        );


        return
        "Client added: "
        +
        argument;

    }



    if(signal=="0xD2")
    {

        return
        "Clients connected: "
        +
        std::to_string(
            globalServer.clientCount()
        );

    }



    return
    "Unknown server signal";


}
