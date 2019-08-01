#include <stdio.h>
#include <stdlib.h>
#include "TYPEDef.h"

void requestElements(UINT32_T **pUINT32_Array, UINT32_T *pUINT32_Size);
void insertionSort(UINT32_T **pUINT32_Array, UINT32_T UINT32_Size);
void printArray(UINT32_T *pUINT32_Array, UINT32_T UINT32_Size);
INT32_T binarySearch(UINT32_T *pUINT32_Array, UINT32_T UINT32_IdxFirstElement, UINT32_T UINT32_IdxLastElement, UINT32_T UINT32_ElementToSearch);

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

/* L'array in input deve essere ordinato! */
INT32_T binarySearch(UINT32_T *pUINT32_Array, UINT32_T UINT32_IdxFirstElement, UINT32_T UINT32_IdxLastElement, UINT32_T UINT32_ElementToSearch)
{
    UINT32_T UINT32_Idx = 0;

    if( (UINT32_ElementToSearch < *(pUINT32_Array+UINT32_IdxFirstElement)) || (UINT32_ElementToSearch > *(pUINT32_Array+UINT32_IdxLastElement) ))
    {
        return -1;
    }
    while(UINT32_IdxFirstElement <= UINT32_IdxLastElement)
    {
        UINT32_Idx = (UINT32_T)((UINT32_IdxFirstElement+UINT32_IdxLastElement)/2);
        
        if( *(pUINT32_Array+UINT32_Idx) == UINT32_ElementToSearch)
        {
            return UINT32_Idx;

        }
        if( *(pUINT32_Array+UINT32_Idx) > UINT32_ElementToSearch)
        {
            UINT32_IdxLastElement = UINT32_Idx-1;
        }
        else
        {
            UINT32_IdxFirstElement = UINT32_Idx+1;
        }
        
    }

    return -1;
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
    printf("Element at: %d\n", binarySearch(pUINT32_Array, 0, UINT32_ArraySize-1, 1));
    printArray(pUINT32_Array, UINT32_ArraySize);

    return 0;
}