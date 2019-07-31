#include <stdio.h>
#include <stdlib.h>
#include "TYPEDef.h"

void requestElements(UINT32_T **pUINT32_Array, UINT32_T *pUINT32_Size);
void insertionSort(UINT32_T **pUINT32_Array, UINT32_T UINT32_Size);
void printArray(UINT32_T *pUINT32_Array, UINT32_T UINT32_Size);

void requestElements(UINT32_T **pUINT32_Array, UINT32_T *pUINT32_Size)
{
    UINT32_T UINT32_Idx;
    printf("Dichiarare il numero di elementi:");
    scanf("%u", pUINT32_Size);

    *pUINT32_Array = (UINT32_T *)malloc(*pUINT32_Size * sizeof(UINT32_T));

    for(UINT32_Idx = 0; UINT32_Idx < *pUINT32_Size; UINT32_Idx++)
    {
        printf("Inserire [%d]:", UINT32_Idx);
        scanf("%u", *pUINT32_Array+UINT32_Idx);
    }
}

void insertionSort(UINT32_T **pUINT32_Array, UINT32_T UINT32_Size)
{
    UINT32_T UINT32_Idx;
    UINT32_T UINT32_Value = 0;
    INT32_T INT32_I = 0;

    for(UINT32_Idx = 1; UINT32_Idx < UINT32_Size; UINT32_Idx++)
    {
        UINT32_Value = (*pUINT32_Array)[UINT32_Idx];
        INT32_I = UINT32_Idx - 1;
        
        while(INT32_I >= 0 && (((*pUINT32_Array)[INT32_I]) > UINT32_Value))
        {

            (*pUINT32_Array)[INT32_I + 1] = (*pUINT32_Array)[INT32_I];
            INT32_I = INT32_I - 1;
            
        }
        (*pUINT32_Array)[INT32_I+1] = UINT32_Value;
    }
}

void printArray(UINT32_T *pUINT32_Array, UINT32_T UINT32_Size)
{
    UINT32_T UINT32_Idx;

    for(UINT32_Idx = 0; UINT32_Idx < UINT32_Size; UINT32_Idx++)
    {
        printf("%d\n", *(pUINT32_Array + UINT32_Idx));
    }
}

int main()
{
    UINT32_T *pUINT32_Array;
    UINT32_T UINT32_ArraySize;

    requestElements(&pUINT32_Array, &UINT32_ArraySize);
    insertionSort(&pUINT32_Array, UINT32_ArraySize);
    printArray(pUINT32_Array, UINT32_ArraySize);

    return 0;
}