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

struct NODE_TS
{
    INT32_T INT32_Key;
    struct NODE_TS *pNODE_Left;
    struct NODE_TS *pNODE_Right;
};

#endif