#ifndef _stack_h
#define _stack_h
#include <stdio.h>
#define Maxsize 10
typedef int ElemType; // Define the type of elements in the stack
typedef struct _stack {
    ElemType data[Maxsize]; // array to store stack elements
    int top;           // index of the top element in the stack
} Stack;
void stack_init(Stack &S);
bool stackEmpty(Stack &S);
bool stackpush(Stack &S, ElemType x);
bool stackpop(Stack &S, ElemType &x);
bool stacktop(Stack &S, ElemType &x);
bool stackclear(Stack &S);
bool stackprint(Stack &S);
#endif