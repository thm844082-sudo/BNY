#include "../include/svrb_runner.hpp"

#include "../include/parser.hpp"
#include "../include/router.hpp"



void SVRBRunner::run(
    std::vector<std::string> code,
    Terminal &terminal
)
{


    terminal.write(
        "[SVRB] Starting program"
    );



    Parser parser;


    Router router;



    auto instructions =
    parser.parse(
        code
    );



    for(
        auto inst:
        instructions
    )
    {


        terminal.write(
            "[LINE "
            +
            std::to_string(inst.line)
            +
            "] "
            +
            inst.signal
        );



        std::string result =
        router.execute(
            inst.signal,
            inst.argument
        );



        terminal.write(
            result
        );


    }



    terminal.write(
        "[SVRB] Program finished"
    );


}
