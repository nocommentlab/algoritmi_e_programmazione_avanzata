#include <stdio.h>
#include <stdlib.h>
#include "TYPEDef.h"
#include "DLL_Lib.h"


int main()
{

    /* Start with the empty list */
    struct NODE_TS* pNODE_Head = NULL; 
  
    /* Let us create the doubly linked list 10<->8<->4<->2 */
    Push(&pNODE_Head, 2); 
    Push(&pNODE_Head, 4); 
    Push(&pNODE_Head, 8); 
    Push(&pNODE_Head, 10); 
  
    printf("\n Original Linked list "); 
    PrintList(pNODE_Head); 
  
    /* delete nodes from the doubly linked list */
    DeleteNode(&pNODE_Head, pNODE_Head); /*delete first node*/
    DeleteNode(&pNODE_Head, pNODE_Head->pNODE_Next); /*delete middle node*/
    DeleteNode(&pNODE_Head, pNODE_Head->pNODE_Next); /*delete last node*/
    
    DeleteNodeAtGivenPos(&pNODE_Head, 10);
    /* Modified linked list will be NULL<-8->NULL */
    printf("\n Modified Linked list "); 
    PrintList(pNODE_Head);

    return 0;
}