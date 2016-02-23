#include <iostream>
#include "display.h"
#include "container.h"
#include "time.h"
#include "datime.h"

using namespace std;

Display :: Display(char input){
    this->disp_setInput(input);
}

void Display :: init_Menu(){
    bool flag = false;
    cout << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << "\t\t\tBuild Your Schedule\t\t\t" << endl;
    cout << "________________________________________________________________________________" << endl << endl << endl;
    cout << "-  (M)ake an Appointment" << endl << endl;
    cout << "-  (F)ind an Appointment" << endl << endl;
    cout << "-  (C)ancel an Appointment" << endl << endl;
    cout << "-  C(H)ange an Appointment" << endl << endl;
    cout << "-  (D)isplay Appointment(s)" << endl << endl;
    cout << "-  (Q)uit" << endl << endl;
    cin >> input;
    this->selection();
}

void Display :: selection(){
    Container appt;
    while(true){
        switch(input){
            case 'm':
                cout << "Making a new Appointment" << endl;
                cout << "________________________________________________________________________________" << endl << endl << endl;
                appt.cont_makeAppt();
                this->init_Menu();
                break;
            case 'f':
                cout << "Finding a new Appointment" << endl;
                appt.cont_findAppt();
                this->init_Menu();
                break;
            case 'c':
                cout << "Cancel an Appointment" << endl;
                appt.cont_cancelAppt();
                this->init_Menu();
                break;
            case 'h': 
                cout << "Change an Appointment" << endl;
                appt.cont_changeAppt();
                this->init_Menu();
                break;
            case 'd': 
                cout << "Display Appointment" << endl;
                appt.cont_disp();
                this->init_Menu();
                break;
            case 'q':
                exit(1);
                break;
            default : 
                cin >> input;
                break;
        }
     }
}

void Display :: disp_setInput(char ninput){
    input = ninput;
}


