#include <stdio.h>
#include <stdlib.h>
#include "TYPEDef.h"

INT32_T partion(UINT32_T **pUINT32_Array, INT32_T INT32_Low, INT32_T INT32_High);
void quickSort(UINT32_T **pUINT32_Array, INT32_T INT32_Low, INT32_T INT32_High);
void printArray(UINT32_T *pUINT32_Array, UINT32_T UINT32_ArraySize);
void requestElements(UINT32_T **pUINT32_Array, UINT32_T *pUINT32_ArraySize);
void swapElements(UINT32_T *pUINT32_FirstElement, UINT32_T *pUINT32_SecondElement);

void swapElements(UINT32_T *pUINT32_FirstElement, UINT32_T *pUINT32_SecondElement)
{
    UINT32_T UINT32_TempValue;
    UINT32_TempValue = *pUINT32_FirstElement;
    *pUINT32_FirstElement = *pUINT32_SecondElement;
    *pUINT32_SecondElement = UINT32_TempValue;

}

INT32_T partion(UINT32_T **pUINT32_Array, INT32_T INT32_Low, INT32_T INT32_High)
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
            swapElements( &(*pUINT32_Array)[INT32_I], &(*pUINT32_Array)[INT32_Idx]);
        }
    }
    
    swapElements( &(*pUINT32_Array)[INT32_I + 1], &(*pUINT32_Array)[INT32_High]);

    return (INT32_I + 1);
} 

// Caso Migliore: T(n) = 2T(n/2)+)(n) => T(n) = O(nlogn)- Partizioni bilanciate
// Caso Pegiore: T(n) = T(n-1) + T(1) + O(n) = T(n)= O(n+n+n(n-1)+....+2) =  Θ(n^2)
// Caso Medio: (O(nlogn)) essa rappresenta la migliore complessita' possibile basato sui confronti
// Dove O(n) e' il costo di partition
void quickSort(UINT32_T **pUINT32_Array, INT32_T INT32_Low, INT32_T INT32_High)
{
    INT32_T INT32_Pi = 0;
    if(INT32_Low < INT32_High)
    {
        INT32_Pi = partion(pUINT32_Array, INT32_Low, INT32_High);

        quickSort(pUINT32_Array, INT32_Low, INT32_Pi - 1);
        quickSort(pUINT32_Array, INT32_Pi + 1, INT32_High);
    }
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
    UINT32_T *pUINT32_Array;
    UINT32_T UINT32_ArraySize;

    requestElements(&pUINT32_Array,&UINT32_ArraySize);
    quickSort(&pUINT32_Array, 0, UINT32_ArraySize - 1);
    printArray(pUINT32_Array, UINT32_ArraySize);
    return 0;
}