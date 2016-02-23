
/*
 *  File:  time_c
 *  Name:
 *  login: 
 *  Date:  25 Aug 07
 *  Mod:
 */

/*  Implementation of Time data type operations
 */


#include <iostream>
#include "time.h"
#include "common.h"

/*
#define DEBUG
*/

/* Initialization functions   */

Time :: Time(int hour, int minute){
    this->time_SetHour(hour);
    this->time_SetMinute(minute);
}
/*Time :: time_Init(Time &t, int hour, int minute)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_Init\n");
	#endif

	time_SetHour(t, hour);
	time_SetMinute(t, minute);

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_Init\n");
	#endif
}

void Time :: time_InitSingle(Time &t, int hrmin)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_InitSingle\n");
	#endif

	time_SetHour(t, hrmin/100);
	time_SetMinute(t, hrmin%100);

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_InitSingle\n");
	#endif
} */

void Time :: time_Clear()
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_Clear\n");
	#endif

	this->time_SetHour(0);
	this->time_SetMinute(0);

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_Clear\n");
	#endif
}

void Time :: time_Copy(Time source)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_Copy\n");
	#endif
    
     minute = source.minute;
     hour = source.hour;

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_Copy\n");
	#endif
}

/* Accessor functions  */
/*inline int Time :: time_GetHour()
{
	#ifdef DEBUG
	fprintf(stderr, "\tExecute time_GetHour\n");
	#endif

	return hour;
}
*/
/*
inline int Time :: time_GetMinute()
{
	#ifdef DEBUG
	fprintf(stderr, "\tExecute time_GetMinute\n");
	#endif

	return minute;
}
*/
/* Mutator functions  */
/*
inline void Time :: time_SetHour(int nhour)
{
	 #ifdef DEBUG
	fprintf(stderr, "\tEnter time_SetHour\n");
	#endif

    hour = nhour;

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_SetHour\n");
	#endif 
}
*/
/*
inline void Time :: time_SetMinute(int min)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_SetMinute\n");
	#endif 

	minute = min;

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_SetMinute\n");
	#endif 
}
*/
/* Display functions  */
void Time :: time_Display()
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_Display\n");
	#endif

	printf("%02d:%02d", this->time_GetHour(),this->time_GetMinute());

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_Display\n");
	#endif
}

/* Comparison functions  */
Boolean Time ::  time_Equal(Time &b)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_Equal\n");
	#endif
    
    if(this->time_GetHour() == b.time_GetHour() && this->time_GetMinute() == b.time_GetMinute()){
        return TRUE;
    }
    else return FALSE;
	#ifdef DEBUG
	fprintf(stderr, "\tExit time_Equal\n");
    #endif
}

Boolean Time :: time_NotEqual(Time &b)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_NotEqual\n");
	#endif

    if(this->time_GetHour() == b.time_GetHour() && this->time_GetMinute() == b.time_GetMinute()){
        return FALSE;
    }
    else return TRUE;
	#ifdef DEBUG
	fprintf(stderr, "\tExit time_NotEqual\n");
	#endif
}

Boolean Time :: time_LessThan(Time &b)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_LessThan\n");
	#endif
    
    if(this->time_GetHour() < b.time_GetHour() && this->time_GetMinute()< b.time_GetMinute()){
        return TRUE;
    }
    else return FALSE;

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_LessThan\n");
	#endif
}

Boolean Time :: time_GreaterThan(Time &b)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_GreaterThan\n");
	#endif
 
    if(this->time_GetHour() < b.time_GetHour() && this->time_GetMinute() < b.time_GetMinute()){
        return FALSE;
    }
    else return TRUE;

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_GreaterThan\n");
	#endif
}

Boolean Time :: time_LessThanOrEqual(Time &b)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_LessThanOrEqual\n");
	#endif

    if(this->time_GetHour() <= b.time_GetHour() &&
            this->time_GetMinute() < b.time_GetMinute()){
        return TRUE;
    }
    else return FALSE;

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_LessThanOrEqual\n");
	#endif
}

Boolean Time :: time_GreaterThanOrEqual(Time &b)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_GreaterThanOrEqual\n");
	#endif
    if(this->time_GetHour() <= b.time_GetHour() && this->time_GetMinute() < b.time_GetMinute()){
        return FALSE;
    }
    else return TRUE;


	#ifdef DEBUG
	fprintf(stderr, "\tExit time_GreaterThanOrEqual\n");
	#endif
}

/* Manipulation functions  */
void Time :: time_Add( int min)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_Add\n");
	#endif
    minute += min;
    while(minute > 60){
        minute -= 60;
        hour += 1;
    }
        /*minutes += this->time_GetMinute();
        while(minutes > 60){
            minutes -= 60;
            time_SetMinute(a, minutes);
            hour = time_GetHour(a) + 1;
            time_SetHour(a, hour);
        }
        return a;
        */
	#ifdef DEBUG
	fprintf(stderr, "\tExit time_Add\n");
	#endif
}

int Time :: time_Difference(Time &b)
{
	#ifdef DEBUG
	fprintf(stderr, "\tEnter time_Difference\n");
	#endif
   
    int diff;
    int min_diff;
    int i;

    diff = this->time_GetHour() - b.time_GetHour();
    min_diff = this->time_GetMinute() - b.time_GetMinute();
    if(min_diff<0){
        diff -= 1;
        min_diff += 60;
        return min_diff;
    }
    for(i = diff;i>0;i--){
       min_diff += 60;
    }
    return min_diff;

	#ifdef DEBUG
	fprintf(stderr, "\tExit time_Difference\n");
	#endif
}


