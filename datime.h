
/*
 *  File:  datime.h
 *  Name:
 *  login: 
 *  Date:  22 Aug 07
 *  Mod:
 */

/*  Defines the "DaTime" data time and the functions that manipulate it 
 *
 *  A "DaTime" object records the day of the week and time span for
 *  a scheduled event.
 */
#ifndef DATIME
#define DATIME

#include "common.h"
#include "day.h"
#include "time.h"

/*  DaTime data type declaration  */
class DaTime{
    public:
        /* Initialization functions */
        DaTime(Day = ' ', Time = Time(), Time = Time(), int = 0);
        void dt_Clear();
        void dt_Copy(DaTime);
        /* Accessor functions  */
        Day dt_GetDay();
        Time dt_GetStart();
        Time dt_GetEnd();
        int dt_GetDuration();

        /* Mutator functions  */
        void dt_SetDay(Day day);
        void dt_SetStart(Time start);
        void dt_SetEnd(Time end);
        void dt_SetDuration(int duration);


        /* Display functions  */
        void dt_Display();

        /* Comparison functions  */
        Boolean dt_Equal(DaTime b);
        Boolean dt_NotEqual(DaTime b);
        Boolean dt_LessThan(DaTime b);
        Boolean dt_GreaterThan(DaTime b);
        Boolean dt_LessThanOrEqual(DaTime b);
        Boolean dt_GreaterThanOrEqual(DaTime b);
        Boolean dt_Overlap(DaTime b);
        Boolean dt_NonOverlap(DaTime b);

        /* Manipulation functions  */
        void dt_ChangeDay(Day);
        void dt_ChangeDuration(int);
        void dt_ChangeStart(Time);

        void dt_Merge(DaTime b);
        int dt_Difference(DaTime b);

    private:
        Day day;
        Time start;
        Time end;
        int duration;
};

#endif
