#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "node.h"

// Create a new nodss
int main(int argc, char *argv[])
{
    // Node *head = NULL;
    List list;
    list.head = NULL;
    int num;
    do
    {
        printf("Enter a number: ");
        scanf("%d", &num);
        if (num != -1)
        {
            add_node(&list, num);
        }  
    } while (num != -1);
    do
    {
        printf("Enter a number: ");
        scanf("%d", &num);
        if (num != -1)
        {
            list_headinsert(&list, num);
        } 
    } while (num != -1);
    
    print_list(&list); 
    printf("Enter a number to found: ");
    scanf("%d", &num);
    Node *p = list_find(&list, num);
    if (p)
    {
        printf("Found %d\n", p->data);
    }
    else
    {
        printf("Not found %d\n", num);
    }
    // int found = 0;
    // find the node with the given number
    // for(p = list.head; p; p = p->next) {
    //     if(p->data == num) {
    //         printf("Found %d\n", num);
    //         found = 1;
    //         break;
    //     }
    // }
    // if (!found)
    // {
    //     printf("Not found %d\n", num);
    // }
    int i, data;
    printf("Enter the index to insert: ");  
    scanf("%d", &i);
    printf("Enter the data to insert: ");
    scanf("%d", &data);
    if (list_insert(&list, i, data))
    {
        printf("Inserted %d at index %d\n", data, i);
    }
    else
    {
        printf("Failed to insert %d at index %d\n", data, i);
    }
    print_list(&list);
    // free the memory

    list_free(&list);

   // free(list.head);
    return 0;
}

void add_node(List* list, int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    // find the last node
    Node *last = list->head;
    if (last)
    {
        while (last->next)
        {
            last = last->next;
        }
        last->next = new_node;
    }
    else
    {
        list->head = new_node;
    }
}

bool list_delete_by_data(List* list, int num)
{
    Node *q;
    Node *p;
    for(q = NULL, p = list->head; p; q = p, p = p->next)
    {
        if( p->data == num)
        {
            if (q)
            {
                q->next = p->next;
            }
            else
            {
                list->head = p->next;
            }
            free(p);
            break;
        }
        else if (p->next == NULL)
        {
            return false;
        }
    }
    return true;
}

List* list_headinsert(List* list, int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    return list;
}

Node* list_find(List* list, int data)
{
    Node *p;
    for (p = list->head; p && p->data != data; p = p->next)
    {
        // do nothing
    }
    return p;
}

Node* list_find_by_i(List* list, int i){
    if (i < 0)
    {
        return NULL;
    }
    if (i == 0)
    {
        return list->head;
    }
    Node *p = list->head;
    for (int j = 0; j < i && p; j++)
    {
        p = p->next;
    }
    return p;
}

void print_list(List* list)
{
    Node *p;
    /*由于每个节点的 next 成员指向链表中的下一
    个节点，因此 p = p->next 会将 p 更新为下一
    个节点的地址，从而遍历整个链表*/
    for (p = list->head; p; p = p->next)
    {
        printf("%d\t", p->data);
    }
    printf("\n");
}

bool list_insert(List* list, int i, int data)
{
    if (i < 0)
    {
        return false;
    }
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if (i == 0)
    {
        new_node->next = list->head;
        list->head = new_node;
        return true;
    }
    Node *p = list->head;
    for (int j = 0; j < i - 1 && p; j++)
    {
        p = p->next;
    }
    if (!p)
    {
        free(new_node);
        return false;
    }
    new_node->next = p->next;
    p->next = new_node;
    return true;
}

bool list_delete(List* list, int i)
{
    if (i == 0)
    {
        Node *temp = list->head;
        list->head = list->head->next;
        free(temp);
        return true;
    }
    Node *p = list->head;
    for (int j = 0; j < i - 1 && p; j++)
    {
        p = p->next;
    }
    if (!p || !p->next)
    {
        return false;
    }
    Node *temp = p->next;
    p->next = temp->next;
    free(temp);
    return true;
}

bool list_delete_by_p(Node* p){
    if (p == NULL)
    {
        return false;
    }
    Node *temp = p->next;
    p->data = temp->data;
    p->next = temp->next;
    free(temp);
    return true;
}

bool list_free(List* list)
{
    Node *p = list->head;
    while (p)
    {
        Node *temp = p;
        p = p->next;
        free(temp);
    }
    list->head = NULL;
    return true;
}