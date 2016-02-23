#include <iostream>
#include <string>
#include "datime.h"
#include "time.h"
#include "container.h"
#include <vector>

using namespace std;

Appt :: Appt(string namae, DaTime prd){
    this->appt_setName(name);
    this->appt_setPeriod(period);
}

void Appt :: appt_setName(string namae){
    name.assign(namae);
}

void Appt :: appt_setPeriod(DaTime prd){
    period.dt_SetDay(prd.dt_GetDay());
    period.dt_SetStart(prd.dt_GetStart());
    period.dt_SetEnd(prd.dt_GetEnd());
    //period.dt_SetDuration(prd.dt_GetDuration());
}

string Appt :: appt_getName(){
    return name;
}

DaTime Appt :: appt_getPeriod(){
    return period;
}

void Appt :: appt_displayPeriod(){
    period.dt_Display();
}

Container :: Container(vector <Appt> Sch, int cnt){
    //    this->cont_setSchedule(Sch);
    //Schedule = Sch;
    this->cont_setSchedule(Sch);
    this->cont_setCount(cnt);
}

void Container :: cont_setSchedule(vector <Appt> &sch){
    Schedule = sch;
}

void Container :: cont_setCount(int cnt){
    count = cnt;
}

void Container :: cont_makeAppt(){
    Appt appoint;
    string namae;
    DaTime time;
    Time timer;
    Day day;
    int num;
    bool flag = false;

    cout << "What is the Professor's Name?" << endl;
    cin >> namae;
    appoint.appt_setName(namae);
    cout << "What day is this appointment on (m,t,w,r,f,s,u)?" << endl;
    while(!flag){
        cin >> day;
        switch(day){
            case 'm':
                flag = true;
                break;
            case 't':
                flag = true;
                break;
            case 'w':
                flag = true;
                break;
            case 'r':
                flag = true;
                break;
            case 'f':
                flag = true;
                break;
            case 's':
                flag = true;
                break;
            case 'u':
                flag = true;
                break;
            default:
                cout << "Not a valid day! Try Again!" << endl;
                cout << "What day is this appointment on (m,t,w,r,f,s,u)?" << endl;
                break;
        }
    }
    time.dt_SetDay(day);
    cout << "What is the Start Time Hour?" << endl;
    do{
        cin >> num;
        if(num < 0 || num > 23){
            cout << "Not a valid Hour.. Please use numbers from 0 to 23" << endl;
            cout << "What is the Start Time Hour?" << endl;
        }
    } while(num > 23 || num < 0);
    timer.time_SetHour(num);
    cout << "What is the Start Time Minute?" << endl;
        do{
            cin >> num;
            if(num < 0 || num > 60){
                cout << "Not a valid Minute... Please use numbers from 0 to 59" << endl;
                cout << "What is the Start Time Minute?" << endl;
            }
        } while(num < 0 || num > 60);
    timer.time_SetMinute(num);
    time.dt_SetStart(timer);
    cout << "What is the End Time Hour?" << endl;
    cin >> num;
    timer.time_SetHour(num);
    cout << "What is the End Time Minute?" << endl;
    cin >> num;
    timer.time_SetMinute(num);
    time.dt_SetEnd(timer);
    appoint.appt_setPeriod(time);
    this->cont_setAppt(appoint); 
}

void Container :: cont_setAppt(Appt appoint){
    cout << Schedule[count].appt_getName();
    Schedule[count].appt_setName(appoint.appt_getName());
    Schedule[count].appt_setPeriod(appoint.appt_getPeriod());
    //Schedule[count]Appt(appoint.appt_getName(),appoint.appt_getPeriod());
    cout << Schedule[count].appt_getName() << endl;
    Schedule[count].appt_displayPeriod();
    count++;
}
void Container :: cont_findAppt(){
}

void Container :: cont_cancelAppt(){
}

void Container :: cont_changeAppt(){
}

void Container :: cont_disp(){
}

