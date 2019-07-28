#include <stdio.h>
#include <stdlib.h>

#include "TYPEDef.h"

/* Definizione delle funzioni */
UINT32_T max(UINT32_T num1, UINT32_T num2, UINT32_T num3);
void indexOf(UINT32_T *pUINT32_Array, UINT32_T UINT32_ArraySize, UINT32_T UINT32_Value, BOOL_T *pElementFound);

void requestElements(UINT32_T **pUINT32_Array, UINT32_T *pUINT32_ArraySize);
void heapify(UINT32_T *pUINT32_Array, UINT32_T UINT32_ArraySize, UINT32_T UINT32_IdxRadix);
void buildHeap(UINT32_T *pUINT32_Array, UINT32_T UINT32_ArraySize);
UINT32_T extractMax(UINT32_T *pUINT32_Array, UINT32_T UINT32_ArraySize);
void insert(UINT32_T *pUINT32_Array, UINT32_T UINT32_ArraySize, UINT32_T UINT32_Element);

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

void indexOf(UINT32_T *pUINT32_Array, UINT32_T UINT32_ArraySize, UINT32_T UINT32_Value, BOOL_T *pElementFound)
{
    UINT32_T UINT32_Idx = 0;
    *pElementFound = FALSE;

    while ( (UINT32_Idx < UINT32_ArraySize) && (FALSE != *pElementFound))
    {
        if(UINT32_Value == pUINT32_Array[UINT32_Idx])
        {
            *pElementFound = TRUE;
        }
        UINT32_Idx++;
    } 
    
}
void requestElements(UINT32_T **pUINT32_Array, UINT32_T *pUINT32_ArraySize)
{                    
    printf("Inserisci la dimensione dell'ARRAY:");
    scanf("%d", pUINT32_ArraySize);

    *pUINT32_Array = malloc(*pUINT32_ArraySize * sizeof(UINT32_T));
}

void heapify(UINT32_T *pUINT32_Array, UINT32_T UINT32_ArraySize, UINT32_T UINT32_IdxRadix)
{
    UINT32_T UINT32_IdxLeftChild;
    UINT32_T UINT32_ValueLeftChild;

    UINT32_T UINT32_IdxRightChid;
    UINT32_T UINT32_ValueRightChild;

    UINT32_T UINT32_Max;
    /* Ricava gli indici dei figli sinistro e destro */
    UINT32_IdxLeftChild = 2*UINT32_IdxRadix;
    UINT32_ValueLeftChild = pUINT32_Array[UINT32_IdxLeftChild];
    UINT32_IdxRightChid = 2*UINT32_IdxRadix+1;
    UINT32_ValueRightChild = pUINT32_Array[UINT32_IdxRightChid];

    UINT32_Max = max(pUINT32_Array[UINT32_IdxRadix], UINT32_ValueLeftChild, UINT32_ValueRightChild);

}

int main()
{
    requestElements(&_pUINT32_Array, &_UINT32_ArraySize);

    return 0;
}