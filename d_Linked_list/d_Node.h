#ifndef _NODE_H
#define _NODE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node {
    int data;
    struct _node *next; // pointer to the next node
    struct _node *prev; // pointer to the previous node
} Node;
typedef struct _list {
    Node *head;
} List;
bool add_dNode(List *list, int data);
bool print_list(List *list);
bool insertnextNode(Node *p, Node *s);
bool insertprevNode(Node *p, Node *s);
bool deletenextNode(Node *p);
bool deleteprevNode(Node *p);
#endif