#include <iostream>
#include "datime.h"
#include "time.h"
#include <string>
#include <vector>
#ifndef CONTAINER
#define CONTAINER
#define MAX_SIZE 14
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
        Container(vector <Appt> Schedule = vector<Appt>(MAX_SIZE), int count = 0);
        void cont_findByName();
        void cont_findByDay();
        void cont_findByTime();
        void cont_makeAppt();
        void cont_findAppt();
        void cont_cancelAppt();
        void cont_changeAppt();
        void cont_changeName(int);
        void cont_changeDay(int);
        void cont_changeStart(int);
        void cont_changeEnd(int);
        bool cont_validDay(Day);
        bool is_number(const string s);
        void cont_disp();
        bool conflict();
        void cont_setSchedule(vector <Appt> &Sch);
        void cont_setCount(int count);
        void cont_setAppt(Appt);    
    private:
        vector <Appt> Schedule;
        int count;
};

#endif
