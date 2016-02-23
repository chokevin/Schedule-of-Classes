#include<stdio.h>
#include "datime.h"

/* modifiers */
void setDay(datime *d, char day){
    d->day = day;
}

void setStart(datime *d, time start){
    d->start = start;
}

void setEnd(datime *d, time end){
    d->end = end;
}

/* comparisons */
void compareTime(datime *d1, datime *d2){
    int num;
    if(d1->day > d2->day){
        swapTime(d1,d2);
    }
    else if(d1->start.hour > d2->start.hour){
        swapTime(d1,d2);
    }
    else if(d1->start.minute > d2->start.minute){
        swapTime(d1,d2);
    }
}

void swapTime(datime *d1, datime *d2){
    datime tmp;

    tmp.day = d1->day;
    tmp.start = d1->start;
    tmp.end = d1->end;
    d1->day = d2->day;
    d1->start = d2->start;
    d1->end = d2->end;
    d2->day = tmp.day;
    d2->start = tmp.start;
    d2->end = tmp.end;

}

time timeDifference(datime *d1, datime *d2){
    time timediff;
    timediff.hour = (d2->start.hour) - (d1->end.hour);
    timediff.minute = (d2->start.minute) - (d1->start.minute);
    return timediff;
}

time getTime(int total){
    time time;
    time.hour = total/100;
    time.minute = total%100;
    return time;
}

void getClassTime(datime *d1, datime *d2){
    int total;
    char day1, day2;
    time time1, time2;
    static const char* weekdayname[] = 
    {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    printf("Date of class(M,T,W,R,F):");
    scanf(" %c", &day1);   
    setDay(d1, day1);
    printf("Start hour of class (for example 945):");
    scanf("%d", &total);
    time1 = getTime(total);
    setStart(d1, time1);
    printf("End hour of class (for example 1030):");
    scanf("%d", &total);
    time1 = getTime(total);
    setEnd(d1, time1);
    printf("Date of class(M,T,W,R,F):");
    scanf(" %c", &day2);
    setDay(d2,day2);
    printf("Start hour of class (for example 1145):");
    scanf("%d", &total);
    time2 = getTime(total);
    setStart(d2, time2);
    printf("End hour of class (for example 1230):");
    scanf("%d", &total);
    time2 = getTime(total);
    setEnd(d2, time2);
}


void printSchedule(datime *d1, datime *d2){
    printf("\t\tClass Schedule\t\t\n");
    printf("----------------------------------------------\n");
    printf("First class: %c, %d:%d - %d:%d\n",d1->day,d1->start.hour,d1->start.minute,
            d1->end.hour,d1->end.minute);
    printf("Second class: %c, %d:%d - %d:%d\n",d2->day, d2->start.hour,
            d2->start.minute,d2->end.hour, d2->end.minute);
} 



