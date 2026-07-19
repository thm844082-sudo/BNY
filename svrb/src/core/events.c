#include "../include/events.h"

#include <stdio.h>
#include <string.h>


char current_event[256];

unsigned char action_opcode;

char action_argument[256];



void event_register(char *event)
{
    strcpy(current_event,event);

    printf("EVENT REGISTERED: %s\n",current_event);
}



void event_set_action(unsigned char opcode,char *argument)
{
    action_opcode = opcode;

    strcpy(action_argument,argument);


    printf("ACTION ATTACHED\n");
}



void event_trigger(char *event)
{

    if(strcmp(current_event,event)==0)
    {

        printf("EVENT FIRED: %s\n",event);


        if(action_opcode == 0xB0)
        {
            printf("ALERT: %s\n",action_argument);
        }

    }

}
