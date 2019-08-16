#include <stdio.h>
#include <stdlib.h>
#include "TYPEDef.h"
#include "SORTING_Lib.h"

/* General Purpose */
void RequestElements(UINT32_T **pUINT32_Array, UINT32_T *pUINT32_ArraySize)
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

void PrintArray(UINT32_T *pUINT32_Array, UINT32_T UINT32_ArraySize)
{
    UINT32_T UINT32_Idx;

    for(UINT32_Idx = 0; UINT32_Idx < UINT32_ArraySize; UINT32_Idx++)
    {
        printf("%d\n", pUINT32_Array[UINT32_Idx]);
    }
}

void CountingSort(UINT32_T *pUINT32_Array, UINT32_T UINT32_MaxValue, UINT32_T UINT32_ArraySize, UINT32_T **pUINT32_SortedArray)
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

UINT32_T ExtractMax(UINT32_T **pUINT32_Array, UINT32_T UINT32_ArraySize)
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

void SwapElements(UINT32_T *pUINT32_FirstElement, UINT32_T *pUINT32_SecondElement)
{
    UINT32_T UINT32_TempValue;
    UINT32_TempValue = *pUINT32_FirstElement;
    *pUINT32_FirstElement = *pUINT32_SecondElement;
    *pUINT32_SecondElement = UINT32_TempValue;

}

INT32_T Partion(UINT32_T **pUINT32_Array, INT32_T INT32_Low, INT32_T INT32_High)
{
    INT32_T INT32_Idx = 0;
    UINT32_T UINT32_TempValue;
    
    INT32_T INT32_Pivot = (*pUINT32_Array)[INT32_High];
    INT32_T INT32_I = INT32_Low - 1;

    for(INT32_Idx = INT32_Low; INT32_Idx <= INT32_High -1; INT32_Idx++)
    {
        if((*pUINT32_Array)[INT32_Idx] <= INT32_Pivot)
        {
            INT32_I++;
            SwapElements( &(*pUINT32_Array)[INT32_I], &(*pUINT32_Array)[INT32_Idx]);
        }
    }
    
    SwapElements( &(*pUINT32_Array)[INT32_I + 1], &(*pUINT32_Array)[INT32_High]);

    return (INT32_I + 1);
} 

void QuickSort(UINT32_T **pUINT32_Array, INT32_T INT32_Low, INT32_T INT32_High)
{
    INT32_T INT32_Pi = 0;
    if(INT32_Low < INT32_High)
    {
        INT32_Pi = Partion(pUINT32_Array, INT32_Low, INT32_High);

        QuickSort(pUINT32_Array, INT32_Low, INT32_Pi - 1);
        QuickSort(pUINT32_Array, INT32_Pi + 1, INT32_High);
    }
}

void Heapify(UINT32_T **pUINT32_Array, UINT32_T UINT32_ArraySize, UINT32_T UINT32_IdxRadix)
{
    INT32_T INT32_Largest = UINT32_IdxRadix;
    INT32_T INT32_IdxLeftChild = 2*UINT32_IdxRadix + 1;
    INT32_T INT32_IdxRightChild = 2*UINT32_IdxRadix + 2;
    UINT32_T UINT32_TempValue;

    if( (INT32_IdxLeftChild < UINT32_ArraySize) && 
        ((*pUINT32_Array)[INT32_IdxLeftChild] > (*pUINT32_Array)[INT32_Largest]))
    {
        INT32_Largest = INT32_IdxLeftChild;
    }

    if( (INT32_IdxRightChild < UINT32_ArraySize) && 
        ((*pUINT32_Array)[INT32_IdxRightChild] > (*pUINT32_Array)[INT32_Largest]))
    {
        INT32_Largest = INT32_IdxRightChild;
    }

    if(INT32_Largest != UINT32_IdxRadix)
    {
        UINT32_TempValue = (*pUINT32_Array)[UINT32_IdxRadix];
        (*pUINT32_Array)[UINT32_IdxRadix] = (*pUINT32_Array)[INT32_Largest];
        (*pUINT32_Array)[INT32_Largest] = UINT32_TempValue;

        Heapify(pUINT32_Array, UINT32_ArraySize, INT32_Largest);
    }

}

/* Time complexity of createAndBuildHeap() is O(n) */
void BuildHeap(UINT32_T **pUINT32_Array, UINT32_T UINT32_ArraySize)
{
    INT32_T INT32_Idx;

    for(INT32_Idx = ((UINT32_ArraySize / 2) - 1); INT32_Idx >=0; INT32_Idx--)
    {
        Heapify(pUINT32_Array, UINT32_ArraySize, INT32_Idx);
    }
}

void HeapSort(UINT32_T **pUINT32_Array, UINT32_T UINT32_ArraySize)
{
    INT32_T INT32_Idx;
    UINT32_T UINT32_TempValue;

    BuildHeap(pUINT32_Array, UINT32_ArraySize);

    for(INT32_Idx = UINT32_ArraySize-1; INT32_Idx >=0; INT32_Idx--)
    {
        UINT32_TempValue = (*pUINT32_Array)[INT32_Idx];
        (*pUINT32_Array)[INT32_Idx] = (*pUINT32_Array)[0];
        (*pUINT32_Array)[0] = UINT32_TempValue;

        Heapify(pUINT32_Array, INT32_Idx, 0);
    }
    
}

void InsertionSort(UINT32_T **pUINT32_Array, UINT32_T UINT32_Size)
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
