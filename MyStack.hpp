//
//  MyStack.hpp
//  data_struct
//
//  Created by weijiazhen on 17/11/3.
//  Copyright © 2017年 weijiazhen. All rights reserved.
//

#ifndef MyStack_hpp
#define MyStack_hpp

#include <stdio.h>

struct ListNode;
typedef ListNode* ListNodePtr;
typedef ListNodePtr Stack;

int IsEmpty(Stack s);
Stack CreateStack();
void DisposeStack(Stack s);
void MakeEmpty(Stack s);
void Push(int x, Stack s);
int Top(Stack s);
void Pop(Stack s);

#endif /* MyStack_hpp */
