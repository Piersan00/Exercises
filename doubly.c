#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* previous;
};

struct DoublyLinkedList {
    struct Node* head;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
}

// insert a new node
void insertAtBeginning(struct DoublyLinkedList* list, int value) {
    struct Node* newNode = createNode(value);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        newNode->next = list->head;
        list->head->previous = newNode;
        list->head = newNode;
    }
}

// insert a new node after
void insertAfter(struct DoublyLinkedList* list, int prevValue, int newValue) {
    struct Node* current = list->head;

    // find the node with the value
    while (current != NULL && current->data != prevValue) {
        current = current->next;
    }

    // if the node is found
    if (current != NULL) {
        struct Node* newNode = createNode(newValue);

        // update pointers
        newNode->next = current->next;
        newNode->previous = current;

        // update pointers of other nodes
        if (current->next != NULL) {
            current->next->previous = newNode;
        }
        current->next = newNode;
    } else {
        printf("Previous element not found in the list.\n");
    }
}

// insert a new node before
void insertBefore(struct DoublyLinkedList* list, int nextValue, int newValue) {
    struct Node* current = list->head;

    // find the node with the value
    while (current != NULL && current->data != nextValue) {
        current = current->next;
    }

    if (current != NULL) {
        struct Node* newNode = createNode(newValue);

        // update pointers
        newNode->next = current;
        newNode->previous = current->previous;

        // update pointers in other nodes
        if (current->previous != NULL) {
            current->previous->next = newNode;
        } else {
            list->head = newNode;
        }
        current->previous = newNode;
    } else {
        printf("Next element not found.\n");
    }
}

// shuffle list using time-based randomization
void shuffleList(struct DoublyLinkedList* list) {
    srand((unsigned int)time(NULL));

    int count = 0;
    struct Node* current = list->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }

    current = list->head;
    for (int i = count - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        // swap values
        int temp = current->data;
        current->data = current->next->data;
        current->next->data = temp;

        current = current->next;
    }
}

// function to print the list
void printList(struct DoublyLinkedList* list) {
    struct Node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct DoublyLinkedList myList;
    myList.head = NULL;

    insertAtBeginning(&myList, 3);
    insertAtBeginning(&myList, 7);
    insertAtBeginning(&myList, 1);
    insertAtBeginning(&myList, 11);
    insertAtBeginning(&myList, 15);

    printf("List before shuffling: ");
    printList(&myList);

    insertAfter(&myList, 7, 5);

    printf("List after insertion: ");
    printList(&myList);

    insertBefore(&myList, 1, 9);

    printf("List after insertion: ");
    printList(&myList);

    shuffleList(&myList);

    printf("List after shuffling: ");
    printList(&myList);

    return 0;
}


