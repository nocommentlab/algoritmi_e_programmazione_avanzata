#ifndef _TYPEDEF_H
#define _TYPEDEF_H

#ifndef TRUE
    #define TRUE 1
#endif

#ifndef FALSE
    #define FALSE 0
#endif


typedef unsigned int UINT32_T;
typedef int INT32_T;
typedef unsigned int BOOL_T;
typedef char CHAR_T;

struct Person
{
    UINT32_T UINT32_Age;
    CHAR_T vCHAR_Name[20];
    struct Person *pNextElement;
};

#endif