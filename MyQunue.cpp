//
//  MyQunue.cpp
//  data_struct
//
//  Created by weijiazhen on 17/11/3.
//  Copyright © 2017年 weijiazhen. All rights reserved.
//

#include "MyQunue.hpp"
#include <stdlib.h>

struct ListNode {
    int value;
    ListNode *next;
};

struct Queue {
    ListNode *head;
    ListNode *tail;
};

Queue* CreateQueue()
{
    Queue *q = (Queue*)malloc(sizeof(struct Queue));
    if (q == nullptr) {
        printf("Create Queue Failed\n");
        return q;
    }
    q->head = nullptr;
    q->tail = nullptr;
    return q;
}

bool IsEmpty(Queue *q)
{
    return q->head == nullptr;
}

void EnQueue(Queue *q, int x)
{
    ListNode *tmp = (ListNode*)malloc(sizeof(struct ListNode));
    tmp->value = x;
    tmp->next = nullptr;
    if (IsEmpty(q)) {
        q->head = tmp;
    } else {
        q->tail->next = tmp;
    }
    q->tail = tmp;
}

void DeQueue(Queue *q)
{
    if (q == nullptr || IsEmpty(q)) {
        printf("Can't dequeue\n");
        return;
    }
    ListNode *p = q->head;
    if (p->next == nullptr) {
        q->head = q->tail = nullptr;
    } else {
        q->head = p->next;
    }
    free(p);
}
