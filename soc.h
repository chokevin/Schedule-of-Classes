#ifndef HELLO
#define HELLO

typedef struct{
    int crn;
    int course_num;
    int section;
    int credit;
    char course_name[];
    char teacher_name[];
    datime info;
    char classroom[];
} course;

typedef struct{
    course courses[6];
} schedule;
#endif

/* Initialization Functions */
void soc_Init(course *a, int crn, int num, int sec, int cred, char name[], 
        char teach[], DaTime a, char classroom[]);
void soc_Clear(course *a);
void soc_Copy(course *dest, course *source);

/* Display Function */
void soc_Display(schedule *a);

/* Accessor Functions */
int soc_GetCrn(course *a);
int soc_GetNum(course *a);
int soc_GetSection(course *a);
int soc_GetCredit(course *a);
char soc_GetName(course *a);
char soc_GetTeacher(course *a);
datime soc_GetInfo(course *a);
char soc_GetClassroom(course *a);
course soc_GetCourse(schedule *a, int n);

/* Mutator Functions */
void soc_SetCrn(course *a, int Crn);
void soc_SetNum(course *a, int Num);
void soc_SetSection(course *a, int Sec);
void soc_SetCredit(course *a, int cred);
void soc_SetName(course *a, char name[]);
void soc_SetTeacher(course *a, char name[]);
void soc_SetInfo(course *a, DaTime info);
void soc_SetClassroom(course *a, char classroom[] );
void soc_SetCourse(schedule *a, course b, int n);

/* Comparison Functions */
Boolean soc_Equal(course *a, course *b);
Boolean soc_NotEqual(course *a, course *b);

/*Manipulation Functions */
void soc_ChangeCrn(course *a, int crn);
void soc_ChangeNum(course *a, int num);
void soc_ChangeSection(course *a, int sec);
void soc_ChangeCredit(course *a, int cred);
void soc_ChangeName(course *a, char name[]);
void soc_ChangeTeacher(course *a, char namep[]);
void soc_ChangeInfo(course *a, DaTime *a);
void soc_ChangeClassroom(course *a, char a[]);
void soc_AddCourse(schedule *a, course b, int n);
void soc_DeleteCourse(schedule *a, int n);
void soc_ChangeCourse(schedule *a, course b, int n);
void soc_SwitchCourse(schedule *a, int i, int j);
int soc_Difference(course *a, course *b);
