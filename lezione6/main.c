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
    
    /* Dichiaro un contatore di elementi */
    UINT32_T UINT32_Counter=0;
    /* Dichiaro un puntatore temporaneo ad un elemento della lista */
    struct Element *pTempElement;
    
    /* Se la list punta a NULL vuol dire che la lista e' vuota */
    if(*pElementList == NULL) return 0;

    /* Assegno al puntatore temporaneo l'indirizzo del primo elemento della lista */
    pTempElement = *pElementList;
    /* Incremento il valore del contatore */
    UINT32_Counter++;
    
    /* Ciclo sin quando ci sono elementi  */
    while(pTempElement->pNextElement != NULL)
    {
        /* Assegno al puntatore temporaneo l'indirizzo di memoria del porssimo elemento della lista */
        pTempElement = pTempElement->pNextElement;
        /* Incremento il valore del contatore */
        UINT32_Counter++;
    } 

    /* Restituisco il numero di elementi contati */
    return UINT32_Counter;
}

void requestNewElement(struct Element **pElement)
{
    
    /* Alloca la memomoria ed inserisce l'indirizzo puntato da pElement */
    *pElement= (struct Element *)malloc(sizeof(struct Element));

    printf("Inserisci il valore da inserire di IDX:");
    scanf("%u", &((*pElement)->UINT32_Idx));
}

/* Inserimento in testa */
void pushHeadElement(struct Element **pElementList, struct Element *pElement)
{
    /* Assegna al puntatore del prossimo elemento dell'elemento da inserire
        l'indirizzo di memoria della testa della lista */
    pElement->pNextElement = *pElementList;
    
    /* Aggiorno la testa della lista con l'indirizzo di memoria del nuovo elemento */
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
    /* Assegna all'indirizzo dell'elemento passato come parametro
        l'indirizzo dell'elemento in testa della coda 
    */
    *pElement = *pElementList;
    /* Assegna l'indirizzo del secondo elemento presente in coda come testa della lista */
    *pElementList = (*pElementList)->pNextElement;
}

/* Cancellazione in coda */
void popLastElement(struct Element **pElementList, struct Element **pElement)
{
    /* Crea un puntatore ad un elemento temporaneo */
    struct Element *pTempElement;

    /* Verifica che la lista abbia un solo elemento */
    if(countListElements(pElementList) == 1) 
    {
        /* Effettua la pop dell'unico elemento */
        pop(pElementList, pElement);
        return;
    }
    /* Assegno al puntatore temporaneo l'indirizzo del primo elemento della lista */
    pTempElement = *pElementList;

    /* Verifico che il valore successivo sia diverso da null */
    while(pTempElement->pNextElement->pNextElement != NULL)
    {
        /* Assegna al puntatore temporaneo l'elemento successivo della lista */
        pTempElement = pTempElement->pNextElement;
    }
    
    /* Assegna al puntatore di element l'indirizzo dell'ultimo elemento */
    *pElement =pTempElement->pNextElement;
    /* Imposta a NULL l'ultimo puntatore di collegamento per interrompere la lista */
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
    struct Element *pTempElement;
    UINT32_T UINT32_Idx = 0;

    pTempElement = *pElementList;

    if(UINT32_Position == 0){ pop(pElementList, &pTempElement); return;}
    if(UINT32_Position == (countListElements(pElementList)-1)){popLastElement(pElementList, &pTempElement); return;} 

    while(pTempElement->pNextElement != NULL)
    {
        if(UINT32_Idx == (UINT32_Position-1))
        {
            
            pTempElement->pNextElement = pTempElement->pNextElement->pNextElement;
            free(pTempElement->pNextElement);
        }
        pTempElement = pTempElement->pNextElement;
        UINT32_Idx++;
    }
   
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

    printf("Primo: %p\n", &pElement);
    initList(&pElementsList);

    requestNewElement(&pElement);
    push(&pElementsList, pElement);

    requestNewElement(&pElement);
    push(&pElementsList, pElement);

    requestNewElement(&pElement);
    push(&pElementsList, pElement);
    
    requestNewElement(&pElement);
    push(&pElementsList, pElement);

    deleteElementAt(&pElementsList, 3);
    
    //printf("%d", pElement->UINT32_Idx);
    /* requestNewElement(&pElement);


    push(&pElementsList, pElement);

    printf("%d\n", countListElements(&pElementsList));


    printList(&pElementsList); */

    printList(&pElementsList);
    
    return 0;
}

