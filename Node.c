//
//  Node.c
//  CommandLinePrc
//
//  Created by 孙培峰 on 1/24/15.
//  Copyright (c) 2015 孙培峰. All rights reserved.
//

#include "Node.h"

int IsEmpty(List list){
    return list->Next == NULL;
}

int IsLast(List list, Position p){
    return p->Next == NULL;
}

Position Find(ElementType X, List list){
    Position p;
    p = list->Next;
    while (p != NULL && p->Element != X) {
        p = p->Next;
    }
    return p;
}

void Delete(ElementType X, List list){
    Position p,tmpCell;
    p = FindPrevious(X, list);
    if (!IsLast(list, p)) {
        tmpCell = p->Next;
        p->Next = tmpCell->Next;
        free(tmpCell);
    }
}

Position FindPrevious(ElementType X, List list){
    Position p;
    p = list;
    while (p->Next != NULL && p->Next->Element != X) {
        p = p->Next;
    }
    return p;
}

void Insert(ElementType X, List list, Position p){
    Position tmpCell;
    tmpCell = malloc(sizeof(struct Node));
    if (tmpCell == NULL) {
        printf("dsf");
    }
    tmpCell->Element = X;
    tmpCell->Next = p->Next;
    p->Next = tmpCell;
}


#pragma mark 以下为自己写的

List MakeEmpty(List list){
    Position p, tmpCell;
    p = list;
    tmpCell = p->Next;
    if (p == NULL) {
        
    }
    do {
        free(p);
        p = tmpCell;
        tmpCell = tmpCell->Next;
    } while (p->Next != NULL);
    
    
}































