#ifndef EVENTS_H
#define EVENTS_H


void event_register(char *event);

void event_set_action(unsigned char opcode, char *argument);

void event_trigger(char *event);


#endif
