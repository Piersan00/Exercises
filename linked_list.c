#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// insert a node at the end 
void insertAtEnd(struct Node** head, int value)
{
    struct Node* newNode = createNode(value);

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node* temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// remove node by its value
void removeNode(struct Node** head, int value)
{
    if (*head == NULL)
    {
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    // search node to remove and keep track of the previous node
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // if the node to remove is the first in the list
    if (temp != NULL && temp->data == value)
    {
        if (prev != NULL)
        {
            prev->next = temp->next;
        }
        else
        {
            *head = temp->next;
        }
        free(temp);
    }
}

// print the list
void printList(struct Node* head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// reverse the list
void reverseList(struct Node** head)
{
    struct Node* current = *head;
    struct Node* prev = NULL;
    struct Node* next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev; // update the head pointer at the end
}

int main()
{
    struct Node* head = NULL;

    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);

    printf("list:\n");
    printList(head);

    int valueToRemove = 2;
    removeNode(&head, valueToRemove);

    printf("\nlist after removing the node with value %d:\n", valueToRemove);
    printList(head);

    // Reverse the list
    reverseList(&head);

    printf("\nreversed list:\n");
    printList(head);

    return 0;
}