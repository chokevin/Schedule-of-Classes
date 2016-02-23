#include <iostream>
#include "container.h"
#include "datime.h"
#include "time.h"
#ifndef DISPLAY
#define DISPLAY

class Display{
    public:
        Display(char input = ' ');
        void init_Menu();
        void selection(); 
        void disp_setInput(char ninput); 

    private:
        char input;
        Container appt;
};
#endif
