#include "../include/router.hpp"

#include <stdexcept>


extern std::string execute_file_signal(
    std::string
);


extern std::string execute_event_signal(
    std::string
);


extern std::string execute_server_signal(
    std::string,
    std::string
);



std::string Router::execute(
    std::string signal,
    std::string argument
)
{


    if(signal=="0xF1")
    {

        return execute_file_signal(
            argument
        );

    }



    if(signal=="0xB0")
    {

        return execute_event_signal(
            argument
        );

    }



    if(
        signal=="0xD0" ||
        signal=="0xD1" ||
        signal=="0xD2"
    )
    {

        return execute_server_signal(
            signal,
            argument
        );

    }



    throw std::runtime_error(
        "Unknown signal: "
        +
        signal
    );


}
