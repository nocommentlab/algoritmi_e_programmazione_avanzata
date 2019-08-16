#ifndef _SORTING_LIB_H
    #define _SORTING_LIB_H


    /* General Purpose */
    void PrintArray(UINT32_T *pUINT32_Array, UINT32_T UINT32_ArraySize);
    void RequestElements(UINT32_T **pUINT32_Array, UINT32_T *pUINT32_ArraySize);
    UINT32_T ExtractMax(UINT32_T **pUINT32_Array, UINT32_T UINT32_ArraySize);
    void SwapElements(UINT32_T *pUINT32_FirstElement, UINT32_T *pUINT32_SecondElement);

    /*
    Migl.: O(n+k); Medio: O(n+k); Pegg: O(n+k); Mem: O(n+k); Stabile
    */
    void CountingSort(UINT32_T *pUINT32_Array, UINT32_T UINT32_MaxValue, UINT32_T UINT32_ArraySize, UINT32_T **pUINT32_SortedArray);
    
    INT32_T Partion(UINT32_T **pUINT32_Array, INT32_T INT32_Low, INT32_T INT32_High);
    /*
    Migl.: O(nlogn); Medio: O(nlogn); Pegg: O(nlogn); Mem: O(1);
    */
    void QuickSort(UINT32_T **pUINT32_Array, INT32_T INT32_Low, INT32_T INT32_High);

    void Heapify(UINT32_T **pUINT32_Array, UINT32_T UINT32_ArraySize, UINT32_T UINT32_IdxRadix);
    void BuildHeap(UINT32_T **pUINT32_Array, UINT32_T UINT32_ArraySize);
    /*
    Migl.: O(nlogn); Medio: O(nlogn); Pegg: O(n^2); Mem: O(logn);
    */
    void HeapSort(UINT32_T **pUINT32_Array, UINT32_T UINT32_ArraySize);

    /*
    Migl.: O(n); Medio: O(n^2); Pegg: O(n^2); Mem: O(1); Stabile
    */
    void InsertionSort(UINT32_T **pUINT32_Array, UINT32_T UINT32_Size);
#endif