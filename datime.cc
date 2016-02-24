
/*
 *  File:  datime.c
 *  Name:
 *  login: 
 *  Date:  25 Aug 07
 *  Mod:
 */

/*  Implementation of DaTime data type operations
*/


#include <iostream>
#include "time.h"
#include "datime.h"
#include "common.h"

/*
#define DEBUG
*/

/* Initialization functions   */

DaTime :: DaTime(Day day, Time start, Time end, int dur)
{	
#ifdef DEBUG
    fprintf(stderr,"\tEnter dt_Init\n");
#endif

    this->dt_SetDay(day);
    this->dt_SetStart(start);
    this->dt_SetEnd(end);
    this->dt_SetDuration(dur);

#ifdef DEBUG
    fprintf(stderr, "\tExit dt_Init\n");
#endif
}

void DaTime :: dt_Clear()
{	
#ifdef DEBUG
    fprintf(stderr,"\tEnter dt_Clear\n");
#endif

    this->dt_SetDay('\0');
    start.time_Clear();
    end.time_Clear();

#ifdef DEBUG
    fprintf(stderr, "\tExit dt_Clear\n");
#endif
}

void DaTime :: dt_Copy( DaTime source)
{
#ifdef DEBUG
    fprintf(stderr,"\tEnter dt_Copy\n");
#endif

    day = source.day;
    start = source.start;
    end = source.end;

#ifdef DEBUG
    fprintf(stderr, "\tExit dt_Copy\n");
#endif
}


/* Accessor functions  */
Day DaTime :: dt_GetDay()
{
#ifdef DEBUG
    fprintf(stderr,"\tExecute dt_GetDay\n");
#endif

    return day;
}

Time DaTime :: dt_GetStart()
{
#ifdef DEBUG
    fprintf(stderr,"\tExecute dt_GetStart\n");
#endif

    return start;   
}

Time DaTime :: dt_GetEnd()
{
#ifdef DEBUG
    fprintf(stderr,"\tExecute dt_GetEnd\n");
#endif

    return end;
}

int DaTime :: dt_GetDuration()
{
#ifdef DEBUG
    fprintf(stderr,"\tExecute dt_GetDuration\n");
#endif

    return duration;

}


/* Mutator functions  */
void DaTime :: dt_SetDay(Day nday)
{
#ifdef DEBUG
    fprintf(stderr,"\tEnter dt_SetDay\n");
#endif
    day = nday;

#ifdef DEBUG
    fprintf(stderr, "\tExit dt_SetDay\n");
#endif
}

void DaTime :: dt_SetStart(Time nstart)
{
#ifdef DEBUG
    fprintf(stderr,"\tEnter dt_SetStart\n");
#endif
    start.time_SetHour(nstart.time_GetHour());
    start.time_SetMinute(nstart.time_GetMinute());
#ifdef DEBUG
    fprintf(stderr, "\tExit dt_SetStart\n");
#endif
}

void DaTime :: dt_SetEnd(Time nend)
{
#ifdef DEBUG
    fprintf(stderr,"\tEnter dt_SetEnd\n");
#endif

    end = nend;

#ifdef DEBUG
    fprintf(stderr, "\tExit dt_SetEnd\n");
#endif
}

void DaTime :: dt_SetDuration(int mins)
{
#ifdef DEBUG
    fprintf(stderr,"\tEnter dt_SetDuration\n");
#endif
    duration = mins;
#ifdef DEBUG
    fprintf(stderr, "\tExit dt_SetDuration\n");
#endif
}



/* Display functions  */
void DaTime :: dt_Display()
{
#ifdef DEBUG
    fprintf(stderr,"\tEnter dt_Display\n");
#endif

    switch(this->dt_GetDay())
    {
        case 'u':	printf("Sunday ");
                    break;
        case 'm':	printf("Monday ");
                    break;
        case 't':	printf("Tuesday ");
                    break;
        case 'w':	printf("Wednesday ");
                    break;
        case 'r':	printf("Thursday ");
                    break;
        case 'f':	printf("Friday ");
                    break;
        case 's':	printf("Saturday ");
                    break;
        default:	printf("Unknown day ");
    };
    start.time_Display();
    putchar('-');
    end.time_Display();
    putchar('\n');

#ifdef DEBUG
    fprintf(stderr, "\tExit dt_Display\n");
#endif
}


/* Comparison functions  */
Boolean DaTime :: dt_Equal(DaTime b)
{
#ifdef DEBUG
    fprintf(stderr,"\tEnter dt_Equal\n");
#endif
    if(start.time_Equal(b.start) && day == b.day)
        return TRUE;
    return FALSE;
#ifdef DEBUG
    fprintf(stderr, "\tExit dt_Equal\n");
#endif
}

Boolean DaTime :: dt_NotEqual(DaTime b)
{
#ifdef DEBUG
    fprintf(stderr,"\tEnter dt_NotEqual\n");
#endif
    if(start.time_NotEqual(b.start) && day != b.day){
        return TRUE;
    }
    return FALSE;
#ifdef DEBUG
    fprintf(stderr, "\tExit dt_NotEqual\n");
#endif
}

Boolean DaTime :: dt_LessThan(DaTime b)
{
#ifdef DEBUG
    fprintf(stderr,"\tEnter dt_LessThan\n");
#endif
    int aday, bday;
    switch(day){
        case 'm':  aday = 1;
        case 't':  aday = 2;
        case 'w':  aday = 3;
        case 'r':  aday = 4;
        case 'f':  aday = 5;
    }
    switch(b.dt_GetDay()){
        case 'm':  bday = 1;
        case 't':  bday = 2;
        case 'w':  bday = 3;
        case 'r':  bday = 4;
        case 'f':  bday = 5;
    }
    if(aday < bday){
        return TRUE;
    }
    if(start.time_LessThan(b.start)){
        return TRUE;
    }
    return FALSE;

#ifdef DEBUG
    fprintf(stderr, "\tExit dt_LessThan\n");
#endif
}

Boolean DaTime :: dt_GreaterThan(DaTime b)
{
#ifdef DEBUG
    fprintf(stderr,"\tEnter dt_GreaterThan\n");
#endif
    int aday, bday, check, hour;
    switch(day){
        case 'm':  aday = 1;
        case 't':  aday = 2;
        case 'w':  aday = 3;
        case 'r':  aday = 4;
        case 'f':  aday = 5;
    }
    switch(b.dt_GetDay()){
        case 'm':  bday = 1;
        case 't':  bday = 2;
        case 'w':  bday = 3;
        case 'r':  bday = 4;
        case 'f':  bday = 5;
    }
    check = aday-bday;
    hour = start.time_Difference(b.start);
    if(check < 0){
        return TRUE;
    }
    if(check > 0){
        return FALSE;
    }
    if(check == 0){
        if(hour < 0){
            return TRUE;
        }
        if(hour > 0){
            return FALSE;
        }
        if(hour == 0){
            if(start.time_LessThan(b.start)){
                return TRUE;
            }
            else return FALSE;
        }
    }

#ifdef DEBUG
    fprintf(stderr, "\tExit dt_GreaterThan\n");
#endif
}

Boolean DaTime :: dt_LessThanOrEqual( DaTime b)
{
#ifdef DEBUG
    fprintf(stderr,"\tEnter dt_LessThanOrEqual\n");
#endif
    int aday, bday, check, hour;
    switch(this->dt_GetDay()){
        case 'm':  aday = 1;
        case 't':  aday = 2;
        case 'w':  aday = 3;
        case 'r':  aday = 4;
        case 'f':  aday = 5;
    }
    switch(b.dt_GetDay()){
        case 'm':  bday = 1;
        case 't':  bday = 2;
        case 'w':  bday = 3;
        case 'r':  bday = 4;
        case 'f':  bday = 5;
    }
    check = aday-bday;
    hour = start.time_Difference(b.start);
    if(check < 0){
        return TRUE;
    }
    if(check > 0){
        return FALSE;
    }
    if(check == 0){
        if(hour < 0){
            return TRUE;
        }
        if(hour > 0){
            return FALSE;
        }
        if(hour == 0){
            if(start.time_LessThan(b.start)){
                return FALSE;
            }
            else return TRUE;
        }
    }


#ifdef DEBUG
    fprintf(stderr, "\tExit dt_LessThanOrEqual\n");
#endif
}

Boolean DaTime :: dt_GreaterThanOrEqual(DaTime b)
{
#ifdef DEBUG
    fprintf(stderr,"\tEnter dt_GreaterThanOrEqual\n");
#endif

    int aday, bday, check, hour;
    switch(this->dt_GetDay()){
        case 'm':  aday = 1;
        case 't':  aday = 2;
        case 'w':  aday = 3;
        case 'r':  aday = 4;
        case 'f':  aday = 5;
    }
    switch(b.dt_GetDay()){
        case 'm':  bday = 1;
        case 't':  bday = 2;
        case 'w':  bday = 3;
        case 'r':  bday = 4;
        case 'f':  bday = 5;
    }
    check = aday-bday;
    hour = start.time_Difference(b.start); 
    if(check < 0){
        return FALSE;
    }
    if(check > 0){
        return TRUE;
    }
    if(check == 0){
        if(hour < 0){
            return FALSE;
        }
        if(hour > 0){
            return TRUE;
        }
        if(hour == 0){
            if(start.time_LessThan(b.start)){
                return FALSE;
            }
            else return TRUE;
        }
    }

#ifdef DEBUG
    fprintf(stderr, "\tExit dt_GreaterThanOrEqual\n");
#endif
}

Boolean DaTime :: dt_Overlap(DaTime b)
{
#ifdef DEBUG
    fprintf(stderr,"\tEnter dt_Overlap\n");
#endif

    int aday, bday, check, hour;
    switch(this->dt_GetDay()){
        case 'm':  aday = 1;
                   break;
        case 't':  aday = 2;
                   break;
        case 'w':  aday = 3;
                   break;
        case 'r':  aday = 4;
                   break;
        case 'f':  aday = 5;
                   break;
        case 's':  aday = 6;
                   break;
        case 'u':  aday = 7;
                   break;
    }
    switch(b.dt_GetDay()){
        case 'm':  bday = 1;
                   break;
        case 't':  bday = 2;
                   break;
        case 'w':  bday = 3;
                   break;
        case 'r':  bday = 4;
                   break;
        case 'f':  bday = 5;
                   break;
        case 's':  bday = 6;
                   break;
        case 'u':  bday = 7;
                   break;
    }
    check = aday-bday;
    hour = start.time_Difference(b.start);
    if(check != 0){
        return FALSE;
    }

    if(check == 0){
        if(start.time_GetHour() == b.start.time_GetHour() && start.time_GetMinute() == b.start.time_GetMinute()){
        return TRUE;
        }
        if(end.time_GetHour() == b.end.time_GetHour() && end.time_GetMinute() == b.start.time_GetMinute()){
        return TRUE;
        }
        if(b.start.time_GetHour() > end.time_GetHour()){
            return FALSE;
        }
        if(b.start.time_GetHour() == end.time_GetHour()){
            if(b.start.time_GetMinute() > end.time_GetMinute()){
                return FALSE;
            }
            if(b.start.time_GetMinute() == end.time_GetMinute()){
                return TRUE;
            }
            if(b.start.time_GetMinute() < end.time_GetMinute()){
                if(b.end.time_GetHour() > start.time_GetHour()){
                    return TRUE;
                }
            }
            if(b.end.time_GetHour() == start.time_GetHour()){
                if(start.time_GetMinute() > b.end.time_GetMinute()){
                    return FALSE;
                }
                if(start.time_GetMinute() == b.end.time_GetMinute()){
                    return TRUE;
                }
                if(start.time_GetMinute() < b.end.time_GetMinute()){
                    return TRUE;
                }
            }
        }
            if(b.start.time_GetHour() < end.time_GetHour()){
                if(b.end.time_GetHour() > start.time_GetHour()){
                    return TRUE;
                }
                if(b.end.time_GetHour() == start.time_GetHour()){
                    if(start.time_GetHour() > b.end.time_GetHour()){
                        return FALSE;
                    }
                }
            }
}

#ifdef DEBUG
    fprintf(stderr, "\tExit dt_Overlap\n");
#endif
}

Boolean DaTime :: dt_NonOverlap(DaTime b)
{
#ifdef DEBUG
    fprintf(stderr,"\tEnter dt_NonOverlap\n");
#endif

    int aday, bday, check, hour;
    switch(this->dt_GetDay()){
        case 'm':  aday = 1;
        case 't':  aday = 2;
        case 'w':  aday = 3;
        case 'r':  aday = 4;
        case 'f':  aday = 5;
    }
    switch(b.dt_GetDay()){
        case 'm':  bday = 1;
        case 't':  bday = 2;
        case 'w':  bday = 3;
        case 'r':  bday = 4;
        case 'f':  bday = 5;
    }
    check = aday-bday;
    hour = start.time_Difference(b.start);
    if(day != 0){
        return TRUE;
    }
    if(day == 0){
        if(start.time_Equal(b.start) && start.time_LessThan(b.start)){
            return FALSE;
        }
        if(end.time_Equal(b.start) && start.time_GreaterThan(b.start)){
            return FALSE;
        }
        return TRUE;
    }


#ifdef DEBUG
    fprintf(stderr, "\tExit dt_NonOverlap\n");
#endif
}


/* Manipulation functions  */
void DaTime :: dt_ChangeDay(Day nday)
{
#ifdef DEBUG
    fprintf(stderr,"\tEnter dt_ChangeDay\n");
#endif
    day = nday;
#ifdef DEBUG
    fprintf(stderr, "\tExit dt_ChangeDay\n");
#endif
}

void DaTime :: dt_ChangeDuration(int dur)
{
#ifdef DEBUG
    fprintf(stderr,"\tEnter dt_ChangeDuration\n");
#endif
    duration = dur;
#ifdef DEBUG
    fprintf(stderr, "\tExit dt_ChangeDuration\n");
#endif
}

void DaTime :: dt_ChangeStart( Time newstart)
{
#ifdef DEBUG
    fprintf(stderr,"\tEnter dt_ChangeStart\n");
#endif
    start = newstart;
#ifdef DEBUG
    fprintf(stderr, "\tExit dt_ChangeStart\n");
#endif
}


void DaTime :: dt_Merge( DaTime b){  
#ifdef DEBUG
    fprintf(stderr,"\tEnter dt_Merge\n");
#endif

    if(this->dt_GetDay() != b.dt_GetDay())
    {	Warning("Cannot merge across days; result cleared");
        this->dt_Clear();
    }

    this->dt_SetDay(b.dt_GetDay());
    this->dt_SetStart(b.dt_GetStart());
    this->dt_SetEnd(b.dt_GetEnd());

#ifdef DEBUG
    fprintf(stderr, "\tExit dt_Merge\n");
#endif
}

int DaTime :: dt_Difference(DaTime b)
{
#ifdef DEBUG
    fprintf(stderr,"\tEnter dt_Difference\n");
#endif

    int aday=0, bday=0, check=0, hour=0, time=0, total_time=0;

    switch(day){
        case 'm':  aday = 1;
        case 't':  aday = 2;
        case 'w':  aday = 3;
        case 'r':  aday = 4;
        case 'f':  aday = 5;
    }
    switch(b.dt_GetDay()){
        case 'm':  bday = 1;
        case 't':  bday = 2;
        case 'w':  bday = 3;
        case 'r':  bday = 4;
        case 'f':  bday = 5;
    }
    check =  bday - aday;
    while(check){
        hour += 24;
        day--;
    }
    time = b.start.time_Difference(end);
    hour += time;
    time = b.start.time_Difference(b.end);
    if(time < 0){
        hour--;
        time += 60;
    }
    return total_time = hour * 100 + time; 
#ifdef DEBUG
    fprintf(stderr, "\tExit dt_Difference\n");
#endif
}



