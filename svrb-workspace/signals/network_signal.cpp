#include "../include/socket_server.hpp"

#include <string>



SocketServer networkServer;



std::string execute_network_signal(
    std::string signal,
    std::string argument
)
{


    if(signal=="0xE0")
    {

        if(
            networkServer.start(
                std::stoi(argument)
            )
        )
        {

            return
            "Network server started";

        }


        return
        "Failed starting server";

    }



    if(signal=="0xE1")
    {

        if(
            networkServer.acceptClient()
        )
        {

            return
            "Client connected";

        }


        return
        "No client connection";

    }



    return
    "Unknown network signal";

}
