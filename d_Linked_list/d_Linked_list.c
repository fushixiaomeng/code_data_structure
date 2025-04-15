#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "d_Node.h"

int main(int argc, char *argv[])
{
    List list;
    list.head = NULL; // Initialize the head pointer to NULL
    int num;
    printf("Enter numbers to insert into the list (enter -1 to stop):\n");
    while (1)
    {
        scanf("%d", &num); // Read an integer from the user
        if (num == -1) // Check for the sentinel value to stop input
        {
            break; // Exit the loop if -1 is entered
        }
        if (!add_dNode(&list, num)) // Insert the number into the list
        {
            printf("Failed to insert %d into the list.\n", num); // Print an error message if insertion fails
        }
    }
    printf("List contents:\n");
    print_list(&list); // Print the contents of the list

    Node *s = (Node *)malloc(sizeof(Node)); // Allocate memory for the new node
    if (s == NULL) // Check if memory allocation was successful
    {
        printf("Memory allocation failed.\n"); // Print an error message if allocation fails
        return 1; // Exit the program with an error code
    }
    printf("Enter a number to insert after the head: ");
    scanf("%d", &s->data); // Read the data for the new node from the user
    s->next = NULL; // Initialize the next pointer of the new node to NULL
    s->prev = NULL; // Initialize the previous pointer of the new node to NULL



    insertnextNode(list.head->next, s); // Insert the new node after the head node
    printf("List contents after insertion:\n");
    print_list(&list); // Print the contents of the list after insertion
    printf("\n"); // Print a newline after printing the list contents

    return 0;
}

bool add_dNode(List *list, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); // Allocate memory for the new node
    if (newNode == NULL) // Check if memory allocation was successful
    {
        return false; // Return false to indicate failure
    }
    newNode->data = data; // Set the data for the new node
    newNode->next = NULL; // Initialize the next pointer to NULL
    newNode->prev = NULL; // Initialize the previous pointer to NULL

    if (list->head == NULL) // If the list is empty, set the head to the new node
    {
        list->head = newNode;
    }
    else // If the list is not empty, insert the new node at the end of the list
    {
        Node *current = list->head;
        while (current->next != NULL) // Traverse to the end of the list
        {
            current = current->next;
        }
        current->next = newNode; // Set the next pointer of the last node to the new node
        newNode->prev = current; // Set the previous pointer of the new node to the last node
    }
    return true; // Return true to indicate success
}

bool print_list(List *list)
{
    Node *p;
    for (p = list->head; p; p = p->next) // Traverse the list and print each node's data
    {
        printf("%d\t", p->data); // Print the data of the current node
    }
    printf("\n"); // Print a newline after printing the list contents
    return true; // Return true to indicate success
}

bool insertnextNode(Node *p, Node *s)
{
    if (p == NULL || s == NULL) // Check if either node is NULL
    {
        return false; // Return false to indicate failure
    }
    s->next = p->next; // Set the next pointer of the new node to the next node of p
    p->next = s; // Set the next pointer of p to the new node
    s->prev = p; // Set the previous pointer of the new node to p
    if (s->next != NULL) // If there is a next node after p
    {
        s->next->prev = s; // Set the previous pointer of the next node to the new node
    }
    return true; // Return true to indicate success
}

bool insertprevNode(Node *p, Node *s)
{
    if (p == NULL || s == NULL) // Check if either node is NULL
    {
        return false; // Return false to indicate failure
    }
    s->prev = p->prev; // Set the previous pointer of the new node to the previous node of p
    p->prev = s; // Set the previous pointer of p to the new node
    s->next = p; // Set the next pointer of the new node to p
    if (s->prev != NULL) // If there is a previous node before p
    {
        s->prev->next = s; // Set the next pointer of the previous node to the new node
    }
    return true; // Return true to indicate success
}

bool deletenextNode(Node *p)
{
    if(p == NULL || p->next == NULL)
    {
        return false; // Return false if p is NULL or if there is no next node
    }
    Node *temp = p->next;
    p->next = temp->next; // Set the next pointer of p to the next node of temp
    if(temp->next != NULL)
    {
        temp->next->prev = p;
    }
    free(temp); // Free the memory allocated for temp
    return true; // Return true to indicate success
}

bool deleteprevNode(Node *p)
{
    if(p == NULL || p->prev == NULL)
    {
        return false; // Return false if p is NULL or if there is no previous node
    }
    Node *temp = p->prev;
    p->prev = temp->prev; // Set the previous pointer of p to the previous node of temp
    if(temp->prev != NULL)
    {
        temp->prev->next = p;
    }
    free(temp); // Free the memory allocated for temp
    return true; // Return true to indicate success
}