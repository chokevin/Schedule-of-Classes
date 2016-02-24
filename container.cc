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
    cout << count << '.' << ' ';
    cout << name << ' ';
    period.dt_Display();
}

Container :: Container(vector <Appt> Sch, int cnt){
    this->cont_setSchedule(Sch);
    this->cont_setCount(cnt);
}

void Container :: cont_setSchedule(vector <Appt> &sch){
    Schedule = sch;
}

void Container :: cont_setCount(int cnt){
    count = cnt;
}

bool Container :: is_number(const string s){
    for(int i = 0; i< s.length(); i++){
        if(isdigit(s[i])){
            return true;
        }
    }
    return false;
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
    while(is_number(namae)){
        cout << "Not a valid name. Please try again with letters only." << endl;
        cout << "What is the Professor's Name?" << endl;
        cin >> namae;
    }
    namae[0] = toupper(namae[0]);
    appoint.appt_setName(namae);
    cout << "What day is this appointment on (m,t,w,r,f,s,u)?" << endl;
    cin >> day;
    while(!cont_validDay(day)){
        cout << "Not a valid day! Try Again!" << endl;
        cout << "What day is this appointment on (m,t,w,r,f,s,u)?" << endl;
        cin >> day;    
    }
    time.dt_SetDay(day);
    cout << "What is the Start Time Hour?" << endl;
    do{
        while(!(cin >> num)){
            cout << "Not a valid number... please use numbers.." << endl;
            cout << "What is the Start Time Hour?" << endl;
            cin.clear();
            cin.ignore(1);
        }
        if(num < 0 || num > 23){
            cout << "Not a valid Hour.. Please use numbers from 0 to 23" << endl;
            cout << "What is the Start Time Hour?" << endl;
        }
    } while(num > 23 || num < 0);
    timer.time_SetHour(num);
    cout << "What is the Start Time Minute?" << endl;
    do{
        while(!(cin >> num)){
            cout << "Not a valid number... please use numbers.." << endl;
            cout << "What is the Start Time Minute?" << endl;
            cin.clear();
            cin.ignore(1);
        }
        if(num < 0 || num > 60){
            cout << "Not a valid Minute... Please use numbers from 0 to 59" << endl;
            cout << "What is the Start Time Minute?" << endl;
        }
    } while(num < 0 || num > 60);
    timer.time_SetMinute(num);
    time.dt_SetStart(timer);
    cout << "What is the End Time Hour?" << endl;
    flag = false;
    do{
        while(!(cin >> num)){
            cout << "Not a valid number... please use numbers.." << endl;
            cout << "What is the End Time Hour?" << endl;
            cin.clear();
            cin.ignore(1);
        }
        if(num < timer.time_GetHour()){
            cout << "This End hour is before the start hour.. Please use numbers above " 
                <<timer.time_GetHour() << endl;
            cout << "What is the End Time Hour?" << endl;
        }
        else if(num < 0 || num > 23){
            cout << "Not a valid hour... Please use numbers from 0 to 23" << endl;
            cout << "What is the End Time Hour?" << endl;
        }
        else{
            flag = true;
        }
    } while(!flag);
    timer.time_SetHour(num);
    cout << "What is the End Time Minute?" << endl;
    flag = false;
    do{
        while(!(cin >> num)){
            cout << "Not a valid number... please use numbers.." << endl;
            cout << "What is the End time minute?" << endl;
            cin.clear();
            cin.ignore(1);
        }
        if(time.dt_GetStart().time_GetHour() == timer.time_GetHour() 
                && num < timer.time_GetMinute()){
            cout << "Not a valid Minute for this hour... Please us numbers above "
                << timer.time_GetMinute() << endl;
            cout << "What is the End Time Minute?" << endl;
        }
        else if(num < 0 || num > 60){
            cout << "Not a valid minute... Please use numbers from 0 to 59" << endl;
            cout << "What is the End Time Minute?" << endl;
        }
        else{
            flag = true;
        }
    } while(!flag);
    timer.time_SetMinute(num);
    time.dt_SetEnd(timer);
    appoint.appt_setPeriod(time);
    this->cont_setAppt(appoint);
    count++;
    if(count == 0){
        cout << "Appointment has been added!" << endl;
    }
    else if(conflict()){
        cout << "There is an appointment conflict!" << endl;
        count--;
    }
    else{
        cout << "Appointment has been added!" << endl;
    }
}

bool Container :: conflict(){
    for(int i= 0; i < count-1; i++){
        if(Schedule[count-1].appt_getPeriod().dt_Overlap(Schedule[i].appt_getPeriod())){
            return true;
        }
    }
    return false;
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
    n[0] = toupper(n[0]);
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
    cout << "Which appointment do you want to cancel? (0 to cancel)" << endl;
    cin >> i;
    if(i != 0){
        while(!flag){
            if(i < 0 || i > count || i > MAX_SIZE){
                cout << "This is not a valid appointment to cancel. Please choose an appointment less than " << count << endl;
                cout << "Which appointment do you want to cancel? (0 to cancel)" << endl;
                cin >> i;
            }
            else{
                flag = true;
            }
        }
        if(i != 0){
            for(i; i<count; i++){
                Schedule[i] = Schedule[i+1];
            }
            count--;
        }
        else{
        }
    }
    else{
    }
}

void Container :: cont_changeAppt(){
    int i;
    char input;
    bool flag = false;
    cout << "Which appointment do you want to change? (0 to exit)" << endl;
    cin >> i;
    if(i != 0){
        while(!flag){
            if(i < 0 || i > count || i > MAX_SIZE){
                cout << "This is not a valid appointment to cancel. Please choose an appointment less than " << count << endl;
                cout << "Which appointment do you want to change? (0 to exit)" << endl;
                cin >> i;
            }
            else{
                flag = true;
            }
        }
        if(i != 0){
            cout << "Would you like to edit the (N)ame, (D)ay, (S)tart Time, or (E)nd Time?" << endl;
            cin >> input;
            flag = false;
            while(!flag){
                switch(input){
                    case 'n':
                        this->cont_changeName(i);
                        cout << "Do you want to change something else? (press 'q' to cancel)" 
                            << endl;
                        cin >> input;
                        break;
                    case 'd':
                        this->cont_changeDay(i);
                        cout << "Do you want to change something else? (press 'q' to cancel)"
                            << endl;
                        cin >> input;
                        break;
                    case 's':
                        this->cont_changeStart(i);
                        cout << "Do you want to change something else? (press 'q' to cancel)" 
                            << endl;
                        cin >> input;
                        break;
                    case 'e':
                        this->cont_changeEnd(i);
                        cout << "Do you want to change something else? (press 'q' to cancel)" 
                            << endl;
                        cin >> input;
                        break;
                    case 'q':
                        flag = true;
                        break;
                    default:
                        cout << "Please pick a valid command (n,d,s,e,q)" << endl;
                        cout << 
                            "Would you like to edit the (N)ame, (D)ay, (S)tart Time, or (E)nd Time?" 
                            << endl;
                        cin >> input;
                        break;
                }
            }
        }
        else{
        }
    }
    else{
    }
}

bool Container :: cont_validDay(Day day){
    switch(day){
        case 'm':
            return true;
        case 't':
            return true;
        case 'w':
            return true;
        case 'r':
            return true;
        case 'f':
            return true;
        case 's':
            return true;
        case 'u':
            return true;
        default:
            return false;
    }
}

void Container :: cont_changeName(int i){
    string n;
    cout << "Input new name" << endl;
    cin >> n;
    n[0] = toupper(n[0]);
    Schedule[i-1].appt_setName(n);
}

void Container :: cont_changeDay(int i){
    Day day;
    DaTime new_datime;
    bool flag = false;
    cout << "Input new day" << endl;
    cin >> day;
    while(!cont_validDay(day)){
        cout << "Not a valid day! Please use a valid choice (m,t,w,r,f,s,u)";
        cout << "Input new day" << endl;
        cin >> day;
    }
    new_datime.dt_SetDay(day);
    new_datime.dt_SetStart((Schedule[i-1].appt_getPeriod()).dt_GetStart());
    new_datime.dt_SetEnd((Schedule[i-1].appt_getPeriod()).dt_GetEnd());
    Schedule[i-1].appt_setPeriod(new_datime);
}

void Container :: cont_changeStart(int i){
    Time Start;
    int hour, min;
    bool flag = false;
    DaTime new_datime;
    cout << "Input new start hour" << endl;
    cin >> hour;
    while(!flag){
        if(((Schedule[i-1].appt_getPeriod()).dt_GetEnd()).time_GetHour() < hour){
            cout << "Not a valid hour. Please use an hour that is less than " 
                << Schedule[i-1].appt_getPeriod().dt_GetEnd().time_GetHour() << endl;
            cout << "Input new start hour" << endl;
            cin >> hour;
        }
        else{
            flag = true;
        }
    }
    Start.time_SetHour(hour);
    cout << "Input new start minute" << endl;
    cin >> min;
    flag = false;
    while(!flag){
        if(Schedule[i-1].appt_getPeriod().dt_GetEnd().time_GetHour() == hour && Schedule[i-1].appt_getPeriod().dt_GetEnd().time_GetMinute() < min){
            cout << "Not a valid minute. Please use an minute that is less than " 
                << Schedule[i-1].appt_getPeriod().dt_GetEnd().time_GetMinute() << endl;
            cout << "Input new start minute" << endl;
            cin >> min;
        }
        else{
            flag = true;
        }
    }
    Start.time_SetMinute(min);
    new_datime.dt_SetDay((Schedule[i-1].appt_getPeriod()).dt_GetDay());
    new_datime.dt_SetStart(Start);
    new_datime.dt_SetEnd((Schedule[i-1].appt_getPeriod()).dt_GetEnd());
    Schedule[i-1].appt_setPeriod(new_datime);

}

void Container :: cont_changeEnd(int i){
    Time End;
    int hour, min;
    DaTime new_datime;
    bool flag = false;
    cout << "Input new End hour" << endl;
    cin >> hour;
    while(!flag){
        if(Schedule[i-1].appt_getPeriod().dt_GetStart().time_GetHour() > hour){
            cout << "Not a valid hour. Please use an hour that is greater than " 
                << Schedule[i-1].appt_getPeriod().dt_GetStart().time_GetHour() << endl;
            cout << "Input new End hour" << endl;
            cin >> hour;
        }
        else{
            flag = true;
        }
    }
    End.time_SetHour(hour);
    flag = false;
    cout << "Input new End minute" << endl;
    cin >> min;
    while(!flag){
        if(Schedule[i-1].appt_getPeriod().dt_GetStart().time_GetHour() == hour && Schedule[i-1].appt_getPeriod().dt_GetStart().time_GetMinute() > min){
            cout << "Not a valid minute. Please use a minute that is greater than " 
                << Schedule[i-1].appt_getPeriod().dt_GetStart().time_GetMinute() << endl;
            cout << "Input new end minute" << endl;
            cin >> min;
        }
        else{
            flag = true;
        }
    } 
    End.time_SetMinute(min);
    new_datime.dt_SetDay((Schedule[i-1].appt_getPeriod()).dt_GetDay());
    new_datime.dt_SetStart((Schedule[i-1].appt_getPeriod()).dt_GetStart());
    new_datime.dt_SetEnd(End);
    Schedule[i-1].appt_setPeriod(new_datime);

}


void Container :: cont_disp(){
    cout << endl << endl << endl;
    cout << "\t\tYour Schedule\t\t" << endl;
    cout << "_______________________________________________________________________" << endl;
    for(int i = 0; i < count; i++){  
        Schedule[i].appt_displayAppt(i+1);
    }
}

