//
//  MyStack.cpp
//  data_struct
//
//  Created by weijiazhen on 17/11/3.
//  Copyright © 2017年 weijiazhen. All rights reserved.
//

#include "MyStack.hpp"
#include <stdlib.h>

struct ListNode {
    int value;
    ListNode *next;
};

int IsEmpty(Stack s)
{
    return s->next == NULL;
}

Stack CreateStack()
{
    Stack s = (Stack)malloc(sizeof(struct ListNode));
    if (s == nullptr) {
        printf("Create Stack Failed\n");
        exit(1);
    }
    s->next = nullptr;
    return s;
}

void MakeEmpty(Stack s)
{
    if (s == nullptr) {
        printf("Stack is NULL\n");
        return;
    } else {
        while (!IsEmpty(s)) {
            Pop(s);
        }
    }
}

// 表头插入元素
void Push(int x, Stack s)
{
    ListNodePtr tmp = (ListNodePtr)malloc(sizeof(struct ListNode));
    if (tmp == nullptr) {
        printf("Out of Space\n");
        return;
    }
    tmp->value = x;
    tmp->next = s->next;
    s->next = tmp;
}

int Top(Stack s)
{
    if (!IsEmpty(s)) {
        return s->next->value;
    }
    printf("Stack is Empty\n");
    return 0;
}

// 表头删除元素
void Pop(Stack s)
{
    if (IsEmpty(s)) {
        printf("Stack is Empty\n");
        return;
    }
    ListNodePtr p = s->next;
    s->next = p->next;
    free(p);
}












