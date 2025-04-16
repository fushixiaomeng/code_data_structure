// Created by Li on 2025/4/15.
#ifndef LISTACK_H
#define LISTACK_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
typedef int ElemType;
typedef struct LiStackNode{
    ElemType data;
    struct LiStackNode *next;
}LiStackNode, *LiStackNodePtr;
typedef struct LiStack{
    LiStackNodePtr top;
    int size;
}LiStack, *LiStackPtr;
bool InitLiStack(LiStackPtr &S); // 初始化栈
bool PushLiStack(LiStackPtr &S, ElemType e); // 进栈
bool PopLiStack(LiStackPtr &S, ElemType &e); // 出栈
bool GetTopLiStack(LiStackPtr S, ElemType &e); // 取栈顶元素
bool IsEmptyLiStack(LiStackPtr S); // 判断栈是否为空
void ClearLiStack(LiStackPtr &S); // 清空栈
void DestroyLiStack(LiStackPtr &S); // 销毁栈
void PrintLiStack(LiStackPtr S); // 打印栈
#endif // LISTACK_H
