#include <stdio.h>
#include <stdlib.h>
#include "TYPEDef.h"

void printArray(UINT32_T *pUINT32_Array, UINT32_T UINT32_ArraySize);
void requestElements(UINT32_T **pUINT32_Array, UINT32_T *pUINT32_ArraySize);
UINT32_T extractMax(UINT32_T **pUINT32_Array, UINT32_T UINT32_ArraySize);
void countingSort(UINT32_T *pUINT32_Array, UINT32_T UINT32_MaxValue, UINT32_T UINT32_ArraySize, UINT32_T **pUINT32_SortedArray);


void requestElements(UINT32_T **pUINT32_Array, UINT32_T *pUINT32_ArraySize)
{       
    UINT32_T UINT32_Idx;

    printf("Inserisci la dimensione dell'ARRAY:");
    scanf("%d", pUINT32_ArraySize);

    *pUINT32_Array = malloc(*pUINT32_ArraySize * sizeof(UINT32_T));

    for(UINT32_Idx=0; UINT32_Idx < *pUINT32_ArraySize; UINT32_Idx++)
    {
        printf("Element[%d]:", UINT32_Idx);
        scanf("%u", &((*pUINT32_Array)[UINT32_Idx]));
    }
}

void printArray(UINT32_T *pUINT32_Array, UINT32_T UINT32_ArraySize)
{
    UINT32_T UINT32_Idx;

    for(UINT32_Idx = 0; UINT32_Idx < UINT32_ArraySize; UINT32_Idx++)
    {
        printf("%d\n", pUINT32_Array[UINT32_Idx]);
    }
}

UINT32_T extractMax(UINT32_T **pUINT32_Array, UINT32_T UINT32_ArraySize)
{
    UINT32_T UINT32_Max = 0;
    UINT32_T UINT32_Idx;

    for(UINT32_Idx =0; UINT32_Idx < UINT32_ArraySize; UINT32_Idx++)
    {
        if((*pUINT32_Array)[UINT32_Idx] > UINT32_Max)
        {
            UINT32_Max = (*pUINT32_Array)[UINT32_Idx];
        }
    }

    return UINT32_Max;
}

// Algoritmo di ordinamento lineare
void countingSort(UINT32_T *pUINT32_Array, UINT32_T UINT32_MaxValue, UINT32_T UINT32_ArraySize, UINT32_T **pUINT32_SortedArray)
{

    UINT32_T *pUINT32_CountArray;
    INT32_T INT32_Idx;

    (*pUINT32_SortedArray) = calloc(UINT32_ArraySize, sizeof(UINT32_T));
    pUINT32_CountArray = calloc(UINT32_MaxValue + 1, sizeof(UINT32_T));

    for(INT32_Idx = 0; pUINT32_Array[INT32_Idx]; ++INT32_Idx)
    {
        ++pUINT32_CountArray[pUINT32_Array[INT32_Idx]];
    }

    for(INT32_Idx = 1; INT32_Idx <= UINT32_MaxValue; ++INT32_Idx)
    {
        pUINT32_CountArray[INT32_Idx] += pUINT32_CountArray[INT32_Idx-1];
    }

    for(INT32_Idx = 0; pUINT32_Array[INT32_Idx]; ++INT32_Idx)
    {
        (*pUINT32_SortedArray)[pUINT32_CountArray[ pUINT32_Array[INT32_Idx]]-1] =  pUINT32_Array[INT32_Idx];
        --pUINT32_CountArray[ pUINT32_Array[INT32_Idx]];
    }
    
    for(INT32_Idx = 0; INT32_Idx< UINT32_ArraySize; INT32_Idx++)
    {
        printf("%d", (*pUINT32_SortedArray)[INT32_Idx]);

    }

}

int main()
{
    UINT32_T *pUINT32_Array;
    UINT32_T *pUINT32_SortedArray;
    UINT32_T UINT32_ArraySize;

    requestElements(&pUINT32_Array, &UINT32_ArraySize);
    countingSort(pUINT32_Array, extractMax(&pUINT32_Array, UINT32_ArraySize), UINT32_ArraySize, &pUINT32_SortedArray);



    return 0;
}