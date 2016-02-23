
/*
 *  File:  time.h
 *  Name:
 *  login: 
 *  Date:  25 Aug 07
 *  Mod:
 */

/*  Defines the "Time" data time and the functions that manipulate it 
 *
 *  A "Time" object records the hours and minutes of a time of day
 */

#ifndef TIME
#define TIME
#include "common.h"


/*  Time data type declaration  */
class Time{	
    private:
        int hour;
        int minute;
    public: 
        /* Initialization functions   */
        Time(int hour = 0,int minute = 0);
        
       // void time_Init(Time &t, int hour, int minute);
       // void time_InitSingle(Time &t, int hrmin);
        void time_Clear();
        void time_Copy(Time source);

        /* Accessor functions  */
        inline int time_GetHour(){
            return hour;
        };

        inline int time_GetMinute(){
            return minute;
        };

        /* Mutator functions  */
        inline void time_SetHour(int nhour){
            hour = nhour;
        };
        inline void time_SetMinute(int min){
            minute = min;
        };

        /* Display functions  */
        void time_Display();

        /* Comparison functions  */
        Boolean time_Equal(Time &b);
        Boolean time_NotEqual( Time &b);
        Boolean time_LessThan( Time &b);
        Boolean time_GreaterThan( Time &b);
        Boolean time_LessThanOrEqual(Time &b);
        Boolean time_GreaterThanOrEqual(Time &b);

        /* Manipulation functions  */
        void time_Add(int minutes);
        int time_Difference(Time &b);
};
#endif
