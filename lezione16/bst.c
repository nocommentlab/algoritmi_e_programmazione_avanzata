#include <stdio.h>
#include <stdlib.h>
#include "TYPEDef.h"

/* 
References:
Online BST Tool: http://btv.melezinek.cz/binary-search-tree.html

Inorder (Left, Root, Right)
Preorder (Root, Left, Right)
Postorder (Left, Right, Root)
*/
struct NODE_TS *newNode(INT32_T INT32_Key);
void inorder(struct NODE_TS *pNODE_Root);
void preorder(struct NODE_TS *pNODE_Root);
void pstorder(struct NODE_TS *pNODE_Root);
struct NODE_TS *insert(struct NODE_TS *pNODE_Node, INT32_T INT32_Key);
struct NODE_TS *search(struct NODE_TS *pNODE_Root, INT32_T INT32_Key);
struct NODE_TS *minValueNode(struct NODE_TS *pNODE_Node);
struct NODE_TS *delete(struct NODE_TS *pNODE_Root, INT32_T INT32_Key);


struct NODE_TS *newNode(INT32_T INT32_Key)
{
    struct NODE_TS *pNODE_Temp = NULL;

    pNODE_Temp = (struct NODE_TS *)malloc(sizeof(struct NODE_TS));
    pNODE_Temp->INT32_Key = INT32_Key;
    pNODE_Temp->pNODE_Left = NULL;
    pNODE_Temp->pNODE_Right = NULL;

    return pNODE_Temp;
}

/* Complessita': θ(h) dove h e' altezza albero */
void inorder(struct NODE_TS *pNODE_Root)
{
    if(NULL != pNODE_Root)
    {
        inorder(pNODE_Root->pNODE_Left);
        printf("%d\n", pNODE_Root->INT32_Key);
        inorder(pNODE_Root->pNODE_Right);
    }
}
void postorder(struct NODE_TS *pNODE_Root)
{
    if(NULL != pNODE_Root)
    {
        postorder(pNODE_Root->pNODE_Left);
        postorder(pNODE_Root->pNODE_Right);
        printf("%d\n", pNODE_Root->INT32_Key);
    }
}

void preorder(struct NODE_TS *pNODE_Root)
{
    if(NULL != pNODE_Root)
    {
        printf("%d\n", pNODE_Root->INT32_Key);
        preorder(pNODE_Root->pNODE_Left);
        preorder(pNODE_Root->pNODE_Right);
        
    }
}

struct NODE_TS *insert(struct NODE_TS *pNODE_Node, INT32_T INT32_Key)
{
    if(NULL == pNODE_Node)
    {
        return newNode(INT32_Key);
    }

    if(INT32_Key < pNODE_Node->INT32_Key)
    {
        pNODE_Node->pNODE_Left = insert(pNODE_Node->pNODE_Left, INT32_Key);
    }
    else if(INT32_Key > pNODE_Node->INT32_Key)
    {
        pNODE_Node->pNODE_Right = insert(pNODE_Node->pNODE_Right, INT32_Key);
        
    }

    return pNODE_Node;

}

/* Complessita: T(n) = T(n/2) + θ(1) => O(log n)
   Caso Peggiore: T(n) = O(h)*/
struct NODE_TS *search(struct NODE_TS *pNODE_Root, INT32_T INT32_Key)
{
    if ((NULL == pNODE_Root) || (INT32_Key == pNODE_Root->INT32_Key))
    {
        return pNODE_Root;
    }

    if(pNODE_Root->INT32_Key < INT32_Key)
    {
        return search(pNODE_Root->pNODE_Right, INT32_Key);
    }

    return search(pNODE_Root->pNODE_Left, INT32_Key);
}

struct NODE_TS *minValueNode(struct NODE_TS *pNODE_Node)
{
    struct NODE_TS *pNODE_CurrentNode = pNODE_Node;

    while(pNODE_CurrentNode && (NULL != pNODE_CurrentNode->pNODE_Left))
    {
        pNODE_CurrentNode = pNODE_CurrentNode->pNODE_Left;
    }

    return pNODE_CurrentNode;
}

/* Caso Peggiore: T(n) = O(h) */
struct NODE_TS *delete(struct NODE_TS *pNODE_Root, INT32_T INT32_Key)
{
    struct NODE_TS *pNODE_Temp = NULL;

    if(NULL == pNODE_Root) return pNODE_Root;
    if (INT32_Key < pNODE_Root ->INT32_Key)
        pNODE_Root->pNODE_Left = delete(pNODE_Root->pNODE_Left, INT32_Key);
    else if (INT32_Key > pNODE_Root->INT32_Key)
        pNODE_Root->pNODE_Right = delete(pNODE_Root->pNODE_Right, INT32_Key);
    else
    {
        if(NULL == pNODE_Root->pNODE_Left)
        {
            pNODE_Temp = pNODE_Root->pNODE_Right;
            free(pNODE_Root);
            return pNODE_Temp;
        }
        else if(NULL == pNODE_Root->pNODE_Right)
        {
            pNODE_Temp = pNODE_Root->pNODE_Left;
            free(pNODE_Root);
            return pNODE_Temp;
        }

        pNODE_Temp = minValueNode(pNODE_Root->pNODE_Right);
        pNODE_Root->INT32_Key = pNODE_Temp->INT32_Key;
        pNODE_Root->pNODE_Right = delete(pNODE_Root->pNODE_Right, pNODE_Temp->INT32_Key);
    }

    return pNODE_Root;
}

int main()
{
    struct NODE_TS *pNODE_Root = NULL;
    pNODE_Root = insert(pNODE_Root, 50);
    insert(pNODE_Root, 30);
    insert(pNODE_Root, 20);
    insert(pNODE_Root, 40);
    insert(pNODE_Root, 70);
    insert(pNODE_Root, 60);
    insert(pNODE_Root, 80);
    insert(pNODE_Root, 10);
    insert(pNODE_Root, 5);

    delete(pNODE_Root, 20);
    inorder(pNODE_Root);

    printf("Found: %d", ((struct NODE_TS *)search(pNODE_Root,60))->INT32_Key);

    return 0;
}