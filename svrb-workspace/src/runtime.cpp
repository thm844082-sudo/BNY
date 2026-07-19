#include "../include/runtime.hpp"



Runtime::Runtime()
{
    running=false;
}



void Runtime::run()
{

    running=true;

    status="SVRB Running...";

}



void Runtime::stop()
{

    running=false;

    status="SVRB Stopped";

}
