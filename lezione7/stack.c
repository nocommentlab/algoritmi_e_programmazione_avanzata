#include <stdio.h>
#include <stdlib.h>

#include "TYPEDef.h"

void initStack(struct Stack **pStack);
void requestElement(struct Stack **pElement);
void printStack(struct Stack *pStack);
void push(struct Stack **pStack, struct Stack **pElement);
void pop(struct Stack **pStack, struct Stack **pElement);


void initStack(struct Stack **pStack)
{
    *pStack = NULL;
}

void requestElement(struct Stack **pElement)
{
    *pElement = (struct Stack *)malloc(sizeof(struct Stack));
    if(*pElement != NULL)
    {
        printf("Inserisci il valore da inserire:");
        scanf("%d", &((*pElement)->UINT32_Value));
        (*pElement)-> pNextElement = NULL;
    }

}
void printStack(struct Stack *pStack)
{
    struct Stack *pTempElement;

    pTempElement = pStack;
    while(pTempElement != NULL)
    {
        printf("%d\n", pTempElement->UINT32_Value);
        pTempElement = pTempElement->pNextElement;
    }
}

void push(struct Stack **pStack, struct Stack **pElement)
{
    if(*pStack == NULL)
    {
        *pStack = *pElement;
    }
    else
    {
        (*pElement)->pNextElement = *pStack;
        *pStack = *pElement;
    }
}

void pop(struct Stack **pStack, struct Stack **pElement)
{
    *pElement = *pStack;
    *pStack = (*pElement)->pNextElement;
}

int main()
{
    struct Stack *pStack;
    struct Stack *pElement;

    initStack(&pStack);

    requestElement(&pElement);
    push(&pStack, &pElement);

    requestElement(&pElement);
    push(&pStack, &pElement);

    requestElement(&pElement);
    push(&pStack, &pElement);
    
    pop(&pStack, &pElement);

    printStack(pStack);


}