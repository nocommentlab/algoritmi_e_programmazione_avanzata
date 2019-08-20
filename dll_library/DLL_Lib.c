#include <stdio.h>
#include <stdlib.h>
#include "TYPEDef.h"
#include "DLL_Lib.h"


void Push(struct NODE_TS** pNODE_HeadRef, INT32_T INT32_Data)
{ 
    struct NODE_TS* pNODE_NewElement = (struct NODE_TS*)malloc(sizeof(struct NODE_TS)); 
  
    pNODE_NewElement->INT32_Data = INT32_Data; 
  

    pNODE_NewElement->pNODE_Next = (*pNODE_HeadRef); 
    pNODE_NewElement->pNODE_Prev = NULL; 
  

    if ((*pNODE_HeadRef) != NULL) 
        (*pNODE_HeadRef)->pNODE_Prev = pNODE_NewElement; 
  
    (*pNODE_HeadRef) = pNODE_NewElement; 
}

void InsertAfter(struct NODE_TS* pNODE_PrevNode, INT32_T INT32_Data) 
{ 
    /*1. check if the given prev_node is NULL */
    if (pNODE_PrevNode == NULL) { 
        printf("the given previous node cannot be NULL"); 
        return; 
    } 
  
    /* 2. allocate new node */
    struct NODE_TS* pNODE_NewElement = (struct NODE_TS*)malloc(sizeof(struct NODE_TS)); 
  
    /* 3. put in the data  */
    pNODE_NewElement->INT32_Data = INT32_Data; 
  
    /* 4. Make next of new node as next of prev_node */
    pNODE_NewElement->pNODE_Next = pNODE_PrevNode->pNODE_Next; 
  
    /* 5. Make the next of prev_node as new_node */
    pNODE_PrevNode->pNODE_Next = pNODE_NewElement; 
  
    /* 6. Make prev_node as previous of new_node */
    pNODE_NewElement->pNODE_Prev = pNODE_PrevNode; 
  
    /* 7. Change previous of new_node's next node */
    if (pNODE_NewElement->pNODE_Next != NULL) 
        ((struct NODE_TS*)(pNODE_NewElement->pNODE_Next))->pNODE_Prev= pNODE_NewElement;
} 

void InsertBefore(struct NODE_TS** pNODE_HeadRef, struct NODE_TS* pNODE_NextRef, INT32_T INT32_Data)  
{  
    /*1. check if the given next_node is NULL */
    if (pNODE_NextRef == NULL) {  
        printf("Il prossimo nodo da inserire non puo' essere NULL");  
        return;  
    }  
  
    /* 2. allocate new node */
    struct NODE_TS* pNODE_NewElement = (struct Node*)malloc(sizeof(struct NODE_TS));  
  
    /* 3. put in the data */
    pNODE_NewElement->INT32_Data = INT32_Data;  
  
    /* 4. Make prev of new node as prev of next_node */
    pNODE_NewElement->pNODE_Prev = pNODE_NextRef->pNODE_Prev;  
  
    /* 5. Make the prev of next_node as new_node */
    pNODE_NextRef->pNODE_Prev = pNODE_NewElement;  
  
    /* 6. Make next_node as next of new_node */
    pNODE_NewElement->pNODE_Next = pNODE_NextRef;  
  
    /* 7. Change next of new_node's previous node */
    if (pNODE_NewElement->pNODE_Prev != NULL)  
        //new_node->prev->next = new_node;
        ((struct NODE_TS *)(pNODE_NewElement->pNODE_Prev))->pNODE_Next = pNODE_NewElement;
    /* 8. If the prev of new_node is NULL, it will be 
       the new head node */
    else
        (*pNODE_HeadRef) = pNODE_NewElement; 
      
}

void DeleteNode(struct NODE_TS** pNODE_HeadRef, struct NODE_TS* pNODE_ToDelete) 
{ 
    /* base case */
    if (*pNODE_HeadRef == NULL || pNODE_ToDelete == NULL) 
        return; 
  
    /* If node to be deleted is head node */
    if (*pNODE_HeadRef == pNODE_ToDelete) 
        *pNODE_HeadRef = pNODE_ToDelete->pNODE_Next; 
  
    /* Change next only if node to be deleted is NOT the last node */
    if (pNODE_ToDelete->pNODE_Next != NULL) 
        ((struct NODE_TS *)pNODE_ToDelete->pNODE_Next)->pNODE_Prev = pNODE_ToDelete->pNODE_Prev; 
  
    /* Change prev only if node to be deleted is NOT the first node */
    if (pNODE_ToDelete->pNODE_Prev != NULL) 
        ((struct NODE_TS *)pNODE_ToDelete->pNODE_Prev)->pNODE_Next = pNODE_ToDelete->pNODE_Next; 
  
    /* Finally, free the memory occupied by del*/
    free(pNODE_ToDelete);

    return; 
}

void DeleteNodeAtGivenPos(struct NODE_TS** pNODE_HeadRef, INT32_T INT32_Position) 
{ 
    INT32_T INT32_Idx;

    /* if list in NULL or invalid position is given */
    if (*pNODE_HeadRef == NULL || INT32_Position <= 0) 
        return; 
  
    struct NODE_TS* pNODE_Current = *pNODE_HeadRef; 
     
  
    /* traverse up to the node at position 'n' from 
       the beginning */
    for ( INT32_Idx = 1; pNODE_Current != NULL && INT32_Idx < INT32_Position; INT32_Idx++) 
        pNODE_Current = pNODE_Current->pNODE_Next; 
  
    /* if 'n' is greater than the number of nodes 
       in the doubly linked list */
    if (pNODE_Current == NULL) 
        return; 
  
    /* delete the node pointed to by 'current' */
    deleteNode(pNODE_HeadRef, pNODE_Current); 
}

void Append(struct NODE_TS** pNODE_HeadRef, INT32_T INT32_Data)
{ 
    /* 1. allocate node */
    struct NODE_TS* pNODE_NewElement = (struct NODE_TS*)malloc(sizeof(struct NODE_TS)); 
  
    struct NODE_TS* pNODE_Last = *pNODE_HeadRef; /* used in step 5*/
  
    /* 2. put in the data  */
    pNODE_NewElement->INT32_Data = INT32_Data; 
  
    /* 3. This new node is going to be the last node, so 
          make next of it as NULL*/
    pNODE_NewElement->pNODE_Next = NULL; 
  
    /* 4. If the Linked List is empty, then make the new 
          node as head */
    if (*pNODE_HeadRef == NULL) { 
        pNODE_NewElement->pNODE_Prev = NULL; 
        *pNODE_HeadRef = pNODE_NewElement; 
        return; 
    } 
  
    /* 5. Else traverse till the last node */
    while (pNODE_Last->pNODE_Next != NULL) 
        pNODE_Last = pNODE_Last->pNODE_Next; 
  
    /* 6. Change the next of last node */
    pNODE_Last->pNODE_Next = pNODE_NewElement; 
  
    /* 7. Make last node as previous of new node */
    pNODE_NewElement->pNODE_Prev = pNODE_Last; 
  
    return; 
} 

void PrintList(struct NODE_TS* pNODE_HeadRef) 
{ 
    while (pNODE_HeadRef != NULL) 
    { 
        printf("%d ", pNODE_HeadRef->pNODE_Next);
        pNODE_HeadRef = pNODE_HeadRef->pNODE_Next; 
    } 
} 