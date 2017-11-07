//
//  BinaryTree.cpp
//  data_struct
//
//  Created by weijiazhen on 17/11/3.
//  Copyright © 2017年 weijiazhen. All rights reserved.
//

#include "BinaryTree.hpp"
#include <stdlib.h>

struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
};

BinaryTree MakeEmpty(BinaryTree t)
{
    if (t != nullptr) {
        MakeEmpty(t->left);
        MakeEmpty(t->right);
        free(t);
    }
    return nullptr;
}

Position Find(int x, BinaryTree t)
{
    if (t == nullptr) {
        return nullptr;
    }
    if (x < t->value)
        return Find(x, t->left);
    else if (x > t->value)
        return Find(x, t->right);
    else
        return t;
}

Position FindMin(BinaryTree t)
{
    if (t == nullptr) {
        return nullptr;
    } else if (t->left == nullptr){
        return t;
    } else {
        return FindMin(t->left);
    }
}

Position FindMax(BinaryTree t)
{
    if (t != nullptr) {
        while (t->right != nullptr) {
            t = t->right;
        }
    }
    return t;
}

BinaryTree Insert(int x, BinaryTree t)
{
    if (t == nullptr) {
        t = (TreeNodePtr)malloc(sizeof(struct TreeNode));
        if (t == nullptr) {
            printf("Out of Space\n");
            exit(1);
        } else {
            t->value = x;
            t->left = t->right = nullptr;
        }
    } else if (x < t->value) {
        t->left = Insert(x, t->left);
    } else if (x > t->value) {
        t->right = Insert(x, t->right);
    }
    return t;
}

BinaryTree Delete(int x, BinaryTree t)
{
    if (t == nullptr) {
        printf("Element Not Found\n");
    } else {
        if (x < t->value) {
            Delete(x, t->left);
        } else if (x > t->value) {
            Delete(x, t->right);
        } else {
            Position tmp;
            if (t->left && t->right) {
                tmp = FindMin(t->right);
                t->value = tmp->value;
                t->right = Delete(t->value, t->right);
            } else {
                tmp = t;
                if (t->left == nullptr)
                    t = t->right;
                else if (t->right == nullptr)
                    t = t->left;
                free(tmp);
            }
        }
    }
    return t;
}














