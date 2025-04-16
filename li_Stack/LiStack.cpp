#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "LiStack.h"

int main(int argc, char *argv[])
{
    LiStackPtr S;
    ElemType e;
    InitLiStack(S);
    for (int i = 0; i < 10; i++)
    {
        PushLiStack(S, i);
    }
    PrintLiStack(S);
    GetTopLiStack(S, e);
    std::cout << "栈顶元素为：" << e << std::endl;
    PopLiStack(S, e);
    std::cout << "出栈元素为：" << e << std::endl;
    PrintLiStack(S);
    IsEmptyLiStack(S);
    ClearLiStack(S);
    DestroyLiStack(S);
}

bool InitLiStack(LiStackPtr &S) // 初始化栈
{
    S = (LiStackPtr)malloc(sizeof(LiStack));
    if (S == NULL)
    {
        return false;
    }
    S->top = NULL;
    S->size = 0;
    return true;
}

bool PushLiStack(LiStackPtr &S, ElemType e) // 进栈，链表头插入 
{
    LiStackNodePtr p = (LiStackNodePtr)malloc(sizeof(LiStackNode));
    if (p == NULL)
    {
        return false;
    }
    p->data = e;
    p->next = S->top;
    S->top = p;
    S->size++;
    return true;
}

bool PopLiStack(LiStackPtr &S, ElemType &e) // 出栈
{
    if (S->top == NULL)
    {
        return false;
    }
    LiStackNodePtr p = S->top;
    e = p->data;
    S->top = p->next;
    free(p);
    S->size--;
    return true;
}

bool GetTopLiStack(LiStackPtr S, ElemType &e) // 取栈顶元素
{
    if (S->top == NULL)
    {
        return false;
    }
    e = S->top->data;
    return true;
}

bool IsEmptyLiStack(LiStackPtr S) // 判断栈是否为空
{
    if (S->top == NULL)
    {
        std::cout << "栈为空" << std::endl;
        return true;
    }
    else
    {
        std::cout << "栈不为空" << std::endl;
        return false;
    }
}

void ClearLiStack(LiStackPtr &S) // 清空栈
{
    LiStackNodePtr p;
    while (S->top != NULL)
    {
        p = S->top;
        S->top = p->next;
        free(p);
    }
    S->size = 0;
}

void DestroyLiStack(LiStackPtr &S) // 销毁栈
{
    ClearLiStack(S);
    free(S);
    S = NULL;
}

void PrintLiStack(LiStackPtr S) // 打印栈
{
    LiStackNodePtr p = S->top;
    std::cout << "栈元素为：";
    while (p != NULL)
    {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}
// Created by Li on 2025/4/15.
