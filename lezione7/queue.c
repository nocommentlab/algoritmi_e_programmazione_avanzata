#include <stdio.h>
#include <stdlib.h>

#ifndef TRUE
    #define TRUE 1
#endif

#ifndef FALSE
    #define FALSE 0
#endif


typedef unsigned int UINT32_T;
typedef int INT32_T;
typedef unsigned int BOOL_T;


struct Queue
{
    UINT32_T UINT32_Value;

    struct Queue *pNextElement;
};

void initQueue(struct Queue **ppQueue);
void requestElement(struct Queue **ppElement);
void printQueue(struct Queue *pQueue);
void enqueue(struct Queue **ppQueue, struct Queue *pQueueElement);
void dequeue(struct Queue **ppQueue, struct Queue **ppElement);


void initQueue(struct Queue **ppQueue)
{
    (*ppQueue) = NULL;
}

void requestElement(struct Queue **ppElement)
{
    *ppElement = (struct Queue *)malloc(sizeof(struct Queue));
    if(*ppElement != NULL)
    {
        printf("Inserisci il valore da inserire:");
        
        scanf("%u", &((*ppElement)->UINT32_Value));
        (*ppElement)->pNextElement = NULL;
    }
}

void printQueue(struct Queue *pQueue)
{
    struct Queue *pTempElement;

    pTempElement = pQueue;
    while(pTempElement != NULL)
    {
        printf("%u", pTempElement->UINT32_Value);
        pTempElement = pTempElement->pNextElement;
    }    
    
}

void enqueue(struct Queue **ppQueue, struct Queue *pQueueElement)
{
    struct Queue *pTempQueueElement;

    if(*ppQueue == NULL)
    {
        /* Non ci sono elementi nella lista */
        *ppQueue = pQueueElement;
    }
    else
    {
        pTempQueueElement = *ppQueue;
        while(pTempQueueElement->pNextElement != NULL)
        {
            pTempQueueElement = pTempQueueElement->pNextElement;
        }

        pTempQueueElement->pNextElement = pQueueElement;
    }
    
}

void dequeue(struct Queue **ppQueue, struct Queue **ppElement)
{
    *ppElement = *ppQueue;

    *ppQueue= (*ppQueue)->pNextElement;

}

int main()
{
    struct Queue *pQueue;
    struct Queue *pElement;

    initQueue(&pQueue);
    requestElement(&pElement);
    enqueue(&pQueue, pElement);

    dequeue(&pQueue, &pElement);

    printQueue(pQueue);
    
    return 0;
}