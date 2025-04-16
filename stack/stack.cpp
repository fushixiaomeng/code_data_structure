#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

int main(int argc, char *argv[]) {
    Stack S; 
    stack_init(S); 
    ElemType x;
    printf("Stack operations:\n");
    printf("1. Push\n2. Pop\n3. Top\n4. Clear\n5. Print\n6. Exit\n");
    int choice;
    while (true) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &x);
                stackpush(S, x);
                break;
            case 2:
                if (stackpop(S, x)) {
                    printf("Popped element: %d\n", x);
                }
                break;
            case 3:
                if (stacktop(S, x)) {
                    printf("Top element: %d\n", x);
                }
                break;
            case 4:
                stackclear(S);
                printf("Stack cleared.\n");
                break;
            case 5:
                stackprint(S);
                break;
            case 6:
                exit(0); // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0; 
}

void stack_init(Stack &S) {
    S.top = -1; // Initialize the top index to -1, indicating an empty stack
}

bool stackEmpty(Stack &S) {
    return S.top == -1; // Check if the stack is empty
}

bool stackpush(Stack &s, ElemType x){
    if(s.top == Maxsize - 1){
        printf("Stack is full\n");
        return false;
    }
    s.data[++s.top] = x; 
    return true; 
}

bool stackpop(Stack &s, ElemType &x){
    if(s.top == -1){
        printf("Stack is empty\n");
        return false; 
    }
    x = s.data[s.top--]; // Pop the top element and decrement the top index
    return true; 
}

bool stacktop(Stack &s, ElemType &x){
    if(s.top == -1){
        printf("Stack is empty\n");
        return false; 
    }
    x = s.data[s.top]; // Get the top element without popping it
    return true; 
}

bool stackclear(Stack &s){
    s.top = -1; // Clear the stack by resetting the top index
    return true; 
}

bool stackprint(Stack &s){
    if(s.top == -1){
        printf("Stack is empty\n");
        return false; 
    }
    for(int i = s.top; i >= 0; i--){
        printf("%d ", s.data[i]); // Print the elements from top to bottom
    }
    printf("\n");
    return true; 
}