#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned int UINT32_T;
typedef int INT32_T;


void allocateSquareMatrixMemory(INT32_T ***ppINT32_Matrix, UINT32_T UINT32_MatrixSize)
{
    UINT32_T UINT32_Idx;
    *ppINT32_Matrix = malloc(UINT32_MatrixSize * sizeof(INT32_T *));
    for(UINT32_Idx = 0; UINT32_Idx < UINT32_MatrixSize; UINT32_Idx++)
    {
        
        (*ppINT32_Matrix)[UINT32_Idx] = calloc(UINT32_MatrixSize, UINT32_MatrixSize * sizeof(INT32_T));
    }

}

void allocateFlatMatrixMemory(INT32_T **pINT32_FlatMatrix, UINT32_T UINT32_MatrixSize)
{
    (*pINT32_FlatMatrix) = (INT32_T *)malloc(UINT32_MatrixSize * UINT32_MatrixSize * sizeof(INT32_T));

}

void requestMatrixData(INT32_T **ppINT32_Matrix, UINT32_T UINT32_MatrixSize)
{
    UINT32_T UINT32_RowIdx, UINT32_ColIdx;
    for(UINT32_RowIdx = 0; UINT32_RowIdx < UINT32_MatrixSize; UINT32_RowIdx++)
    {
        for(UINT32_ColIdx = 0; UINT32_ColIdx < UINT32_MatrixSize; UINT32_ColIdx++)
        {
            printf("Insert [%d][%d]:", UINT32_RowIdx, UINT32_ColIdx);
            scanf("%d", &ppINT32_Matrix[UINT32_RowIdx][UINT32_ColIdx]);
        }
    }
}
void serializeMatrix(INT32_T **ppINT32_Matrix, UINT32_T UINT32_MatrixSize, INT32_T **pINT32_FlatMatrix)
{
    UINT32_T UINT32_RowIdx, UINT32_ColIdx;
    
    for(UINT32_RowIdx = 0; UINT32_RowIdx < UINT32_MatrixSize; UINT32_RowIdx++)
    {
        for(UINT32_ColIdx = 0; UINT32_ColIdx < UINT32_MatrixSize; UINT32_ColIdx++)
        {
            (*pINT32_FlatMatrix)[UINT32_MatrixSize * UINT32_RowIdx + UINT32_ColIdx] = ppINT32_Matrix[UINT32_RowIdx][UINT32_ColIdx];
        }
    }

}

void deserializeArray(INT32_T *pINT32_FlatMatrix, UINT32_T UINT32_FlatMatrixSize, INT32_T ***ppINT32_Matrix)
{
    UINT32_T UINT32_Idx;
    UINT32_T UINT32_RowOffset = 0;
    UINT32_T UINT32_ColOffset = 0;
    UINT32_T UINT32_MatrixColCount ;

    UINT32_MatrixColCount = (UINT32_T)(sqrt(UINT32_FlatMatrixSize));
    (*ppINT32_Matrix)[0][0] = pINT32_FlatMatrix[0];
    
    for(UINT32_Idx = 1; UINT32_Idx < UINT32_FlatMatrixSize; UINT32_Idx++)
    {
        if((UINT32_Idx % UINT32_MatrixColCount) == 0)
        {
            UINT32_RowOffset+=1;
            UINT32_ColOffset =0;
        }
        
        (*ppINT32_Matrix)[UINT32_RowOffset][UINT32_ColOffset]= pINT32_FlatMatrix[UINT32_Idx];

        UINT32_ColOffset+=1;

    }
}

int main()
{
    INT32_T **ppINT32_Matrix;
    INT32_T **ppINT32_DeserializedMatrix;
    INT32_T *pINT32_FlatMatrix;

    UINT32_T UINT32_MatrixSize;
    
    printf("Insert the matrix size:");
    scanf("%u", &UINT32_MatrixSize);

    allocateSquareMatrixMemory(&ppINT32_Matrix, UINT32_MatrixSize);
    allocateSquareMatrixMemory(&ppINT32_DeserializedMatrix, UINT32_MatrixSize);

    allocateFlatMatrixMemory(&pINT32_FlatMatrix, UINT32_MatrixSize);
    
    requestMatrixData(ppINT32_Matrix, UINT32_MatrixSize);

    serializeMatrix(ppINT32_Matrix, UINT32_MatrixSize, &pINT32_FlatMatrix); // pINT32_FlatMatrix Contains the serialized flat matrix

    deserializeArray(pINT32_FlatMatrix, UINT32_MatrixSize*UINT32_MatrixSize, &ppINT32_DeserializedMatrix); // ppINT32_DeserializedMatrix contains the deserialized matrix
    
    
    return 0;
}

