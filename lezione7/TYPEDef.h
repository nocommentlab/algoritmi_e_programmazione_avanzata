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

struct Queue
{
    UINT32_T UINT32_Value;

    struct Queue *pNextElement;
};

struct Stack
{
    UINT32_T UINT32_Value;
    struct Stack *pNextElement;
};

#endif