#ifndef _DLL_LIB_H
    #define _DLL_LIB_H

    void Push(struct NODE_TS** pNODE_HeadRef, INT32_T INT32_Data);
    void InsertAfter(struct NODE_TS* pNODE_PrevNode, INT32_T INT32_Data);
    void InsertBefore(struct NODE_TS** pNODE_HeadRef, struct NODE_TS* pNODE_NextRef, INT32_T INT32_Data) ;
    void DeleteNode(struct NODE_TS** pNODE_HeadRef, struct NODE_TS* pNODE_ToDelete);
    void DeleteNodeAtGivenPos(struct NODE_TS** pNODE_HeadRef, INT32_T INT32_Position);
    void Append(struct NODE_TS** pNODE_HeadRef, INT32_T INT32_Data);
    void PrintList(struct NODE_TS* pNODE_HeadRef) ;
    
#endif