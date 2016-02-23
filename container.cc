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

void Appt :: appt_displayAppt(int count){
    cout << count << ' ';
    cout << name << ' ';
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
    do{
        cin >> num;
        if(num < 0 || num > 23){
            cout << "Not a valid hour... Please use numbers from 0 to 23" << endl;
            cout << "What is the End Time Hour?" << endl;
        }
    } while(num > 23 || num < 0);
    timer.time_SetHour(num);
    cout << "What is the End Time Minute?" << endl;
    do{
        cin >> num;
        if(num < 0 || num > 60){
            cout << "Not a valid Minute... Please use numbers from 0 to 59" << endl;
            cout << "What is the Start Time Minute?" << endl;
        }
    } while(num < 0 || num > 60);
    timer.time_SetMinute(num);
    time.dt_SetEnd(timer);
    appoint.appt_setPeriod(time);
    this->cont_setAppt(appoint);
    count++;
}

void Container :: cont_setAppt(Appt appoint){
    cout << Schedule[count].appt_getName();
    Schedule[count].appt_setName(appoint.appt_getName());
    Schedule[count].appt_setPeriod(appoint.appt_getPeriod());
    cout << Schedule[count].appt_getName() << endl;
    Schedule[count].appt_displayPeriod();
}
void Container :: cont_findAppt(){

    char input;
    bool flag = false;
    cout << "Do you want to search by (N)ame, (D)ay, or (T)ime?" << endl;
    cin >> input;
    while(!flag){
        switch(input){
            case 'n':
                this->cont_findByName();
                cout << "Do you want to search again? (press 'q' to exit)" << endl;
                cin >> input;
                break;
            case 'd':
                this->cont_findByDay();
                cout << "Do you want to search again? (press 'q' to exit)" << endl;
                cin >> input;
                break;
            case 't':
                this->cont_findByTime();
                cout << "Do you want to search again? (press 'q' to exit)" << endl;
                cin >> input;
                break;
            case 'q':
                flag = true;
                break;
            default:
                cout << "Please pick a valid command (n,d,t)" << endl;
                cout << "Do you want to search by (N)ame, (D)ay, or (T)ime?" << endl;
                cin >> input;
                break;
        }
    }
}

void Container :: cont_findByName(){
    string n;
    bool flag = false;
    cout << "\t\tSearching by Name\t\t" << endl;
    cout << "What is the name of the Professor for the appointment?" << endl;
    cin >> n;
    cout << "Searching for Appointments with the following name " << n << endl;
    for(int i =0; i < count; i++){
        if(n == Schedule[i].appt_getName()){
            Schedule[i].appt_displayAppt(i+1);
            flag = true;
        }
    }
    if(!flag){
        cout << "Sorry. We could not find any appointments matching " << n << endl;
    }

}
void Container :: cont_findByDay(){
    Day day;
    bool flag = false;
    cout << "\t\tSearching by Day\t\t" << endl;
    cout << "What is the day of the appointment?" << endl;
    cin >> day;
    cout << "Searching for Appointments on the following day " << day << endl;
    for(int i = 0; i < count; i++){
        if(day == (Schedule[i].appt_getPeriod()).dt_GetDay()){
            Schedule[i].appt_displayAppt(i+1);
            flag = true;
        }
    }
    if(!flag){
        cout << "Sorry. We could not find any appointments matching " << day << endl;
    }
}
void Container :: cont_findByTime(){
    int hour;
    bool flag = false;
    cout << "\t\tSearching by Start Time\t\t" << endl;
    cout << "What is the approximate start hour of the appointment? (+/-3 hours)" << endl;
    cin >> hour;
    cout << "Searching for Appointments around the following hour " << hour << endl;
    for(int i = 0; i < count; i++){
       if(hour-3 == (((Schedule[i].appt_getPeriod()).dt_GetStart()).time_GetHour())||
            hour-2 == (((Schedule[i].appt_getPeriod()).dt_GetStart()).time_GetHour()) ||
            hour-1 == (((Schedule[i].appt_getPeriod()).dt_GetStart()).time_GetHour())|| 
            hour == (((Schedule[i].appt_getPeriod()).dt_GetStart()).time_GetHour())||
            hour+1 == (((Schedule[i].appt_getPeriod()).dt_GetStart()).time_GetHour())||
            hour+2 == (((Schedule[i].appt_getPeriod()).dt_GetStart()).time_GetHour())||
            hour+3 == (((Schedule[i].appt_getPeriod()).dt_GetStart()).time_GetHour())){
           Schedule[i].appt_displayAppt(i+1);
           flag = true;
       }
    }
    if(!flag){
        cout << "Sorry. We could not find any appointments matching a start time around "<< hour << endl;
    }
}



void Container :: cont_cancelAppt(){
    int i;
    bool flag = false;
    cout << "Which appointment do you want to cancel?" << endl;
    while(!flag){
        cin >> i;
        if(i < 0 || i > count || i > MAX_SIZE){
            cout << "This is not a valid appointment to cancel. Please choose an appointment less than " << count << endl;
        }
        else{
            flag = true;
        }
    }
    for(i; i<count; i++){
        Schedule[i] = Schedule[i+1];
    }
    count--;
}

void Container :: cont_changeAppt(){
    int i;
    cout << "Which appointment do you want to change?" << endl;
    cin >> i;
      
}


void Container :: cont_disp(){
    for(int i = 0; i < count; i++){
        cout << "\t\tYour Schedule\t\t" << endl;
        cout << "_______________________________________________________________________" << endl;
        Schedule[i].appt_displayAppt(i+1);
    }
}

