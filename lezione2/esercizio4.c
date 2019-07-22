#include <stdio.h>


typedef unsigned int UINT32_T;
typedef int INT32_T;

UINT32_T UINT32_nRows, UINT32_nCols;
UINT32_T **ppMatrix;
UINT32_T *pFirstElement;

/* http://c-faq.com/aryptr/dynmuldimary.html */
void requestMatrixSize()
{
    printf("Inserisci il numero di righe:");
    scanf("%u", &UINT32_nRows);
    
    printf("Inserisci il numero di colonne:");
    scanf("%u", &UINT32_nCols);
}

void disposeMemory()
{
    UINT32_T UINT32_Idx;
    
    ppMatrix = malloc(UINT32_nRows * sizeof(UINT32_T *));
    for(UINT32_Idx = 0; UINT32_Idx < UINT32_nRows; UINT32_Idx++)
    {
        ppMatrix[UINT32_Idx] = calloc(UINT32_nCols, UINT32_nCols * sizeof(UINT32_T));
    }
    
}

UINT32_T getRandomNumber(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

void incrementValueRandomPosition()
{
    UINT32_T UINT32_NumberOfOperation;
    UINT32_T UINT32_Idx;
    
    printf("Numero di iterazioni:");
    scanf("%u", &UINT32_NumberOfOperation);
    
    for(UINT32_Idx = 0; UINT32_Idx < UINT32_NumberOfOperation; UINT32_Idx++)
    {
        UINT32_T UINT32_RandomRow, UINT32_RandomCol;
        UINT32_RandomRow = getRandomNumber(0, UINT32_nRows-1);
        UINT32_RandomCol = getRandomNumber(0, UINT32_nCols-1);
        
       pFirstElement = &ppMatrix[UINT32_RandomRow][UINT32_RandomCol];
       *pFirstElement+=1;

    }
}


void printMatrix()
{
    UINT32_T UINT32_RowIdx, UINT32_ColIdx;
    
    for(UINT32_RowIdx = 0; UINT32_RowIdx < UINT32_nRows; UINT32_RowIdx++)
    {
        for(UINT32_ColIdx = 0; UINT32_ColIdx < UINT32_nCols; UINT32_ColIdx++)
        {
            printf("%d\t", ppMatrix[UINT32_RowIdx][UINT32_ColIdx]);
            
        }
        
        printf("\n");
    }
}
int main()
{
    requestMatrixSize();
    
    disposeMemory();   
    
    incrementValueRandomPosition();
    
    printMatrix();
    
    return 0;
}