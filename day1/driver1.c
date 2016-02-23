#include<stdio.h>
#include "datime.h"

int main(){
    datime d1, d2;
    int day;
    int hour, min;
    int total;
    time time1;
    
    getClassTime(&d1,&d2);
    compareTime(&d1,&d2);
    printSchedule(&d1,&d2);
} 
