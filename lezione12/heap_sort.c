#include <stdio.h>
#include <stdlib.h>

#include "TYPEDef.h"

/* Definizione delle funzioni */
UINT32_T max(UINT32_T num1, UINT32_T num2, UINT32_T num3);
UINT32_T indexOf(UINT32_T *pUINT32_Array, UINT32_T UINT32_ArraySize, UINT32_T UINT32_Value, BOOL_T *pElementFound);
void requestElements(UINT32_T **pUINT32_Array, UINT32_T *pUINT32_ArraySize);
void heapify(UINT32_T **pUINT32_Array, UINT32_T UINT32_ArraySize, UINT32_T UINT32_IdxRadix);
void buildHeap(UINT32_T **pUINT32_Array, UINT32_T UINT32_ArraySize);
void heapSort(UINT32_T **pUINT32_Array, UINT32_T UINT32_ArraySize);
UINT32_T extractMax(UINT32_T **pUINT32_Array, UINT32_T *pUINT32_ArraySize);
void insert(UINT32_T *pUINT32_Array, UINT32_T UINT32_ArraySize, UINT32_T UINT32_Element);
void printArray(UINT32_T *pUINT32_Array, UINT32_T UINT32_ArraySize);


UINT32_T *_pUINT32_Array;
UINT32_T _UINT32_ArraySize;


UINT32_T max(UINT32_T num1, UINT32_T num2, UINT32_T num3)
{
    /*https://codeforwin.org/2015/05/c-program-to-find-maximum.html*/
    UINT32_T max;
    if(num1 > num2)
    {
        if(num1 > num3)
        {
            /* If num1 > num2 and num1 > num3 */
            max = num1;
        }
        else
        {
            /* If num1 > num2 but num1 > num3 is not true */
            max = num3;
        }
    }
    else
    {
        if(num2 > num3)
        {
            /* If num1 is not > num2 and num2 > num3 */
            max = num2;
        }
        else
        {
            /* If num1 is not > num2 and num2 > num3 */
            max = num3;
        }
    }

    return max;
}

UINT32_T indexOf(UINT32_T *pUINT32_Array, UINT32_T UINT32_ArraySize, UINT32_T UINT32_Value, BOOL_T *pElementFound)
{
    UINT32_T UINT32_Idx = 0;
    *pElementFound = FALSE;

    while ( (UINT32_Idx < UINT32_ArraySize) && (FALSE == *pElementFound))
    {
        
        if(UINT32_Value == pUINT32_Array[UINT32_Idx])
        {
            *pElementFound = TRUE;
        }
        else
        {
            UINT32_Idx++;
        }
    } 
    return UINT32_Idx;
}

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

void heapify(UINT32_T **pUINT32_Array, UINT32_T UINT32_ArraySize, UINT32_T UINT32_IdxRadix)
{
    UINT32_T UINT32_IdxLeftChild;
    UINT32_T UINT32_ValueLeftChild;

    UINT32_T UINT32_IdxRightChid;
    UINT32_T UINT32_ValueRightChild;

    UINT32_T UINT32_Max;
    UINT32_T UINT32_IdxLarghest;
    BOOL_T BOOL_ElementFound;
    UINT32_T UINT32_ElementTemp;

    /* Ricava gli indici dei figli sinistro e destro */
    UINT32_IdxLeftChild = 2*UINT32_IdxRadix+1;
    UINT32_ValueLeftChild = (*pUINT32_Array)[UINT32_IdxLeftChild];
    UINT32_IdxRightChid = 2*UINT32_IdxRadix+2;
    UINT32_ValueRightChild = (*pUINT32_Array)[UINT32_IdxRightChid];

    UINT32_Max = max((*pUINT32_Array)[UINT32_IdxRadix], UINT32_ValueLeftChild, UINT32_ValueRightChild);
    
    UINT32_IdxLarghest = indexOf((*pUINT32_Array), UINT32_ArraySize, UINT32_Max, &BOOL_ElementFound);
    if(TRUE == BOOL_ElementFound)
    {
        if(UINT32_IdxLarghest != UINT32_IdxRadix)
        {
            UINT32_ElementTemp = (*pUINT32_Array)[UINT32_IdxRadix];
            (*pUINT32_Array)[UINT32_IdxRadix] = (*pUINT32_Array)[UINT32_IdxLarghest];
            (*pUINT32_Array)[UINT32_IdxLarghest] = UINT32_ElementTemp;
            
            heapify(&_pUINT32_Array, _UINT32_ArraySize, UINT32_IdxLarghest);

        }
    }
}

void buildHeap(UINT32_T **pUINT32_Array, UINT32_T UINT32_ArraySize)
{
    INT32_T INT32_Idx;

    INT32_Idx = (INT32_T)UINT32_ArraySize-1;

    while(INT32_Idx >= 0)
    {
        heapify(&(*pUINT32_Array), UINT32_ArraySize, INT32_Idx);
        INT32_Idx--;
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

void heapSort(UINT32_T **pUINT32_Array, UINT32_T UINT32_ArraySize)
{
    UINT32_T UINT32_Idx;
    UINT32_T UINT32_Temp;
    
    buildHeap(pUINT32_Array, UINT32_ArraySize);
    
    
    for(UINT32_Idx=UINT32_ArraySize; UINT32_Idx >=1; UINT32_Idx--)
    {
        UINT32_Temp = (*pUINT32_Array)[0];
        (*pUINT32_Array)[0] = (*pUINT32_Array)[UINT32_Idx-1];
        (*pUINT32_Array)[UINT32_Idx-1] = UINT32_Temp;
        printf("Change: %u %u\n", (*pUINT32_Array)[0], (*pUINT32_Array)[UINT32_Idx-1]);
        UINT32_ArraySize--;

        heapify(pUINT32_Array, UINT32_ArraySize, 0);
    }

}

int main()
{
    
    BOOL_T BOOL_ElementFound = FALSE;
    UINT32_T UINT32_IdxFound =0;
    UINT32_T UINT32_Max;
    
    requestElements(&_pUINT32_Array, &_UINT32_ArraySize);

    //buildHeap(&_pUINT32_Array, _UINT32_ArraySize);
    //UINT32_Max = extractMax(&_pUINT32_Array, &_UINT32_ArraySize);
    //printf("Max:%u", UINT32_Max);
    heapSort(&_pUINT32_Array, _UINT32_ArraySize);
    printArray(_pUINT32_Array, _UINT32_ArraySize);
    
    return 0;
}