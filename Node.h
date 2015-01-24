//
//  Node.h
//  CommandLinePrc
//
//  Created by 孙培峰 on 1/24/15.
//  Copyright (c) 2015 孙培峰. All rights reserved.
//

#ifndef __CommandLinePrc__Node__
#define __CommandLinePrc__Node__

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct Node *ptrToNode;
typedef ptrToNode List;
typedef ptrToNode Position;
struct Node{
    ElementType Element;
    Position Next;
};

List MakeEmpty(List list);
int IsEmpty(List list);
int IsLast(List list, Position p);
Position Find(ElementType X, List list);
void Delete(ElementType X, List list);
Position FindPrevious(ElementType X, List list);
void Insert(ElementType X, List list, Position p);
void DeleteList(List list);
Position Header(List list);
Position Advance(Position p);
ElementType Retrieve(Position p);


#endif /* defined(__CommandLinePrc__Node__) */
