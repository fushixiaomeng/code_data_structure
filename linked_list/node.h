#ifndef _NODE_H
#define _NODE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _node {
    int data;
    struct _node *next; // pointer to the next node
} Node;
typedef struct _list {
    Node *head;
} List;
void add_node(List* list, int data);
void print_list(List* list);
bool list_insert(List* list, int i, int data);
bool list_delete(List* list, int i);
bool list_delete_by_p(Node* p);
bool list_delete_by_data(List* list, int data);
bool list_free(List* list);
Node* list_find(List* list, int data);
Node* list_find_by_i(List* list, int i);
List* list_headinsert(List* list, int data);
Node* list_reverse(List* list);
#endif