#include <stdio.h>

/*  */
// Define section
#define MAX_ARRAY_SIZE 3

// typedef section
typedef int INT32_T;
typedef unsigned int UINT32_T;

// Global variables section
UINT32_T _vInputArray[MAX_ARRAY_SIZE];
UINT32_T *pUINT32_InputArray;

// Gets the input array from the user
void readInputArray(UINT32_T vInputArray[])
{
    UINT32_T UINT32_Idx;
    for(UINT32_Idx = 0; UINT32_Idx < MAX_ARRAY_SIZE; UINT32_Idx++)
    {
        printf("vInputArray[%d]:", UINT32_Idx);
        scanf("%u", &vInputArray[UINT32_Idx]);
    }
}

// Sum all of the array elements
UINT32_T sumInputArray()
{
    UINT32_T UINT32_Sum=0;
    UINT32_T UINT32_Idx;
    
    for(UINT32_Idx = 0; UINT32_Idx < MAX_ARRAY_SIZE; UINT32_Idx++)
    {
        UINT32_Sum += *(_vInputArray+UINT32_Idx);
    }
    
    return UINT32_Sum;
}

// Main function
int main()
{
    pUINT32_InputArray = _vInputArray;
    
    readInputArray(_vInputArray);
    
    printf("The sum is: %d", sumInputArray());
    
    return 0;
}