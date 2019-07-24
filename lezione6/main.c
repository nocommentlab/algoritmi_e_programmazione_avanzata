#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

typedef unsigned int UINT32_T;
typedef int INT32_T;
typedef unsigned int BOOL_T;

struct Element
{
    BOOL_T BOOL_HasElements;

    UINT32_T UINT32_Idx;
    struct Element *pNextElement;
};

void initList(struct Element **pElementList)

{   
    /*  Imposta a NULL il puntatore.
        Il puntatore di una lista vuota punta sempre a NULL
      */
    (*pElementList)=NULL;

}

UINT32_T countListElements(struct Element **pElementList)
{
    UINT32_T UINT32_Counter=0;
    struct Element *pTempElement;
    
    pTempElement = *pElementList;
    if((*pElementList)->pNextElement == NULL) return 0;
    UINT32_Counter++;
    while(pTempElement->pNextElement != NULL)
    {
        pTempElement = pTempElement->pNextElement;
        UINT32_Counter++;
    } 
    return UINT32_Counter;
}

void requestNewElement(struct Element **pElement)
{
    
    *pElement= (struct Element *)malloc(sizeof(struct Element));

    printf("Inserisci il valore da inserire di IDX:");
    scanf("%u", &((*pElement)->UINT32_Idx));
}

/* Inserimento in testa */
void pushHeadElement(struct Element **pElementList, struct Element *pElement)
{
    pElement->pNextElement = *pElementList;
    
    *pElementList = pElement;
    
}

/* Inserimento in coda */
void push(struct Element **pElementList, struct Element *pElement)
{
    // Dichiaro un puntatore d'appoggio
    struct Element *pLastElement;

    /* Imposto a NULL il puntatore del prossimo elemento.
        L'ultimo elemento ha il puntatore di successione sempre impostato a NULL
    */  
    pElement->pNextElement = NULL;

    /* Verifica che non siano presenti altri elementi nulla lista */
    if((*pElementList) == NULL)
    {
        // Non essendoci altri elementi, sposta il puntatore alla locazione
        // di memoria dell'elemento passato tramite parametro
        (*pElementList) = pElement;
    }
    else
    {
        /*  Se ci sono elementi, trovo l'ultimo elemento della chain ed accodo il nuovo elemento*/
        
        /*  Faccio puntatore il puntatore temporaneo alla testa della lista */
        pLastElement = *pElementList;
        /* Ciclo sin quando e' presente un elemento successivo */
        while(pLastElement->pNextElement != NULL)
        {
            /*  Faccio puntatore il puntatore temporaneo all'elemento successivo */
            pLastElement = pLastElement->pNextElement;
        }
        /* Aggiorno l'indirizzo del puntatore all'elemento successivo dell'ultimo elemento
            con l'indirizzo di memoria dell'elemento passato per argomento.
        */
        pLastElement->pNextElement = pElement;
       
   }    
}   

/* Cancellazione in testa */
void pop(struct Element **pElementList, struct Element **pElement)
{

    *pElement = *pElementList;
    *pElementList = (*pElementList)->pNextElement;
}

/* Cancellazione in coda */
void popLastElement(struct Element **pElementList, struct Element **pElement)
{
    struct Element *pTempElement;

    pTempElement = *pElementList;
    while(pTempElement->pNextElement->pNextElement != NULL)
    {
        pTempElement = pTempElement->pNextElement;
    }
    
    *pElement =pTempElement->pNextElement;
    pTempElement->pNextElement = NULL;

    free(pTempElement->pNextElement);
    
}

/* Inserimento posizione p. La prima posizione e' 0 */
void insertElementAt(struct Element **pElementList, struct Element *pElement, UINT32_T UINT32_Position)
{
    UINT32_T UINT32_ListIdx = 0;
    struct Element *pTempElement;
    
    pTempElement = *pElementList;
    if( UINT32_Position == 0 ){ 
        pushHeadElement(pElementList, pElement); 
        return;
    }

    if (UINT32_Position >= countListElements(pElementList)){ push(pElementList, pElement); 
        return;
    }
    
    while(pTempElement->pNextElement != NULL)
    {
        if( UINT32_Position == UINT32_ListIdx+1)
        {
            pElement->pNextElement = pTempElement->pNextElement;
            pTempElement->pNextElement = pElement;
        }
        pTempElement= pTempElement->pNextElement;
        UINT32_ListIdx++;
    }

}

/* Cancellazione posizione p */
void deleteElementAt(struct Element **pElementList, UINT32_T UINT32_Position)
{
    /* Da implementare */
}
void printList(struct Element  **pElementsList)
{
    struct Element *tmpElement;
    tmpElement = *pElementsList;
    while (tmpElement != NULL)
    {
        printf("Elemento: %u\n", tmpElement->UINT32_Idx);
        tmpElement = tmpElement->pNextElement;
    }
}


int main()
{
    // Dichiaro la lista degli elementi
    struct Element *pElementsList;
    // Allocazione di memoria utilizzata per gli elementi da aggiungere
    struct Element *pElement;

    struct Element *pElementPopped;
    struct Element *pHeadElement;

    initList(&pElementsList);
    

    requestNewElement(&pElement);

    push(&pElementsList, pElement);

    requestNewElement(&pElement);

    push(&pElementsList, pElement);

    /* requestNewElement(&pElement);

    push(&pElementsList, pElement);

    requestNewElement(&pElement);

    push(&pElementsList, pElement);

    requestNewElement(&pElement);

    push(&pElementsList, pElement);

    requestNewElement(&pElement);
    insertElementAt(&pElementsList, pElement, 0); */

    printList(&pElementsList);
    
    return 0;
}