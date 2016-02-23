#include <iostream>
#include "datime.h"
#include "time.h"
#include <string>
#include <vector>
#ifndef CONTAINER
#define CONTAINER
using namespace std;
class Appt{
    public:
        Appt(string = string(), DaTime = DaTime());
        void appt_setName(string);
        string appt_getName();
        DaTime appt_getPeriod();
        void appt_setPeriod(DaTime);
        void appt_displayPeriod();
        void appt_displayAppt(int );
private:
        string name;
        DaTime period;
};
class Container{
    public:
        Container(vector <Appt> Schedule = vector<Appt>(14), int count = 0);
        void cont_makeAppt();
        void cont_findAppt();
        void cont_findByName();
        void cont_findByDay();
        void cont_findByTime();
        void cont_cancelAppt();
        void cont_changeAppt();
        void cont_disp();
        void cont_setSchedule(vector <Appt> &Sch);
        void cont_setCount(int count);
        void cont_setAppt(Appt);    
    private:
        vector <Appt> Schedule;
        int count;
};

#endif
