#include <iostream>
#include "container.h"
#include "datime.h"
#include "time.h"
#ifndef DISPLAY
#define DISPLAY

class Display{
    public:
        Display(char input = ' ');
        void init_Menu(Container);
        void selection(Container); 
        void disp_setInput(char ninput); 

    private:
        char input;
        Container appt;
};
#endif
