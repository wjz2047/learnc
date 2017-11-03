//
//  MyList.cpp
//  c++_test
//
//  Created by weijiazhen on 17/10/28.
//  Copyright © 2017年 weijiazhen. All rights reserved.
//

#include "MyList.hpp"

#include <stdlib.h>

struct ListNode {
    int value;
    ListNode *next;
};

int IsEmpty(List L)
{
    return L->next == NULL;
}

int IsLast(Position p, List L)
{
    return p->next == NULL;
}

Position Find(int x, List L)
{
    Position p = L->next;
    while (p != NULL && p->value != x) {
        p = p->next;
    }
    return p;
}

Position FindPrevious(int x, List L)
{
    Position p = L;
    while (p->next != NULL && p->next->value != x) {
        p = p->next;
    }
    return p;
}

void Delete(int x, List L)
{
    Position p, tmp;
    p = FindPrevious(x, L);
    if (!IsLast(p, L)) {
        tmp = p->next;
        p->next = tmp->next;
        free(tmp);
    }
}

void Insert(int x, List L, Position p)
{
    Position tmp;
    tmp = (Position)malloc(sizeof(struct ListNode));
    if (tmp == NULL) {
        perror("Out of space!!!");
        exit(1);
    }
    tmp->value = x;
    tmp->next = p->next;
    p->next = tmp;
}

void DeleteList(List L)
{
    Position p, tmp;
    p = L->next;
    L->next = NULL;
    while (p != NULL) {
        tmp = p->next;
        free(p);
        p = tmp;
    }
}
