#include <stdio.h>
typedef int INT32_T;
typedef unsigned int UINT32_T;

void readInputArray(UINT32_T *pUINT32_InputArray, UINT32_T UINT32_Size)
{
    UINT32_T UINT32_Idx;
    
    for(UINT32_Idx = 0; UINT32_Idx < UINT32_Size; UINT32_Idx++)
    {
        printf("vInputArray[%d]:", UINT32_Idx);
        scanf("%u", pUINT32_InputArray+UINT32_Idx);
    }
}

UINT32_T sumInputArray(UINT32_T *pUINT32_InputArray, UINT32_T UINT32_Size)
{
    UINT32_T UINT32_Sum=0;
    UINT32_T UINT32_Idx;
    
    for(UINT32_Idx = 0; UINT32_Idx < UINT32_Size; UINT32_Idx++)
    {
        UINT32_Sum += *(pUINT32_InputArray+UINT32_Idx);
    }
    
    
    return UINT32_Sum;
}

int main()
{
    UINT32_T UINT32_MaxArraySize;
    UINT32_T *pUINT32_InputArray;

    printf("Insert the array size:");
    scanf("%u", &UINT32_MaxArraySize);
    
    pUINT32_InputArray = (UINT32_T*)malloc(UINT32_MaxArraySize * sizeof(UINT32_T));
    
    readInputArray(pUINT32_InputArray, UINT32_MaxArraySize);
    
    printf("The sum is: %d", sumInputArray(pUINT32_InputArray, UINT32_MaxArraySize));
    return 0;
}
