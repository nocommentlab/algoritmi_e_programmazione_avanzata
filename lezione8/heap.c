#include <stdio.h>
#include <stdlib.h>

#include "TYPEDef.h"

/* Definizione delle funzioni */
void requestElements(UINT32_T **pUINT32_Array, UINT32_T *pUINT32_ArraySize);
void heapify(UINT32_T **pUINT32_Array, UINT32_T UINT32_ArraySize, UINT32_T UINT32_IdxRadix);
void buildHeap(UINT32_T **pUINT32_Array, UINT32_T UINT32_ArraySize);
UINT32_T extractMax(UINT32_T **pUINT32_Array, UINT32_T *pUINT32_ArraySize);
void insert(UINT32_T *pUINT32_Array, UINT32_T UINT32_ArraySize, UINT32_T UINT32_Element);
void printArray(UINT32_T *pUINT32_Array, UINT32_T UINT32_ArraySize);


UINT32_T *_pUINT32_Array;
UINT32_T _UINT32_ArraySize;


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

/* Time complexity of heapify is O(Logn) */
void heapify(UINT32_T **pUINT32_Array, UINT32_T UINT32_ArraySize, UINT32_T UINT32_IdxRadix)
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

        heapify(pUINT32_Array, UINT32_ArraySize, INT32_Largest);
    }

}

void buildHeap(UINT32_T **pUINT32_Array, UINT32_T UINT32_ArraySize)
{
    INT32_T INT32_Idx;

    for(INT32_Idx = ((UINT32_ArraySize / 2) - 1); INT32_Idx >=0; INT32_Idx--)
    {
        heapify(pUINT32_Array, UINT32_ArraySize, INT32_Idx);
    }
}

UINT32_T extractMax(UINT32_T **pUINT32_Array, UINT32_T *pUINT32_ArraySize)
{
    UINT32_T UINT32_Max;
    if(*pUINT32_Array == NULL)
    {
        printf("Empty queue");
        return 0;
    }
    else
    {
        UINT32_Max = (*pUINT32_Array)[0];
        (*pUINT32_Array)[0]=(*pUINT32_Array)[*pUINT32_ArraySize-1];
        *pUINT32_ArraySize -=1;
        heapify(pUINT32_Array, *pUINT32_ArraySize, 0);

        return UINT32_Max;
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
int main()
{
    
    BOOL_T BOOL_ElementFound = FALSE;
    UINT32_T UINT32_IdxFound =0;
    UINT32_T UINT32_Max;
    
    requestElements(&_pUINT32_Array, &_UINT32_ArraySize);

    buildHeap(&_pUINT32_Array, _UINT32_ArraySize);
    //UINT32_Max = extractMax(&_pUINT32_Array, &_UINT32_ArraySize);
    //printf("Max:%u", UINT32_Max);

    printArray(_pUINT32_Array, _UINT32_ArraySize);
    
    return 0;
}