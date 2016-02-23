#include<stdio.h>
#ifndef DATIME_H
#define DATIME_H

typedef struct{
    int hour;
    int minute;
} time;

typedef struct{
    char day;
    time start;
    time end;
} datime;
#endif

void setday(datime *d, int day);
void setStart(datime *d, time start);
void setEnd(datime *d, time end);
void compareTime(datime *d1, datime *d2);
time getTime(int total);
time timeDifference(datime *d1, datime *d2);
void getClassTime();
void printSchedule(datime *d1, datime *d2);
