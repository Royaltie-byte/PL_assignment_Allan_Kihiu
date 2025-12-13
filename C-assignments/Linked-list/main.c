#include <stdio.h>
#include <stdlib.h>

//structure of a node
struct Node {
    int data;
    struct Node *next;
};


//linked list structure
struct LinkedList {
    struct Node *head;
    int size;
};

//function prototypes
void insertAt(struct LinkedList *list, int index, int value);
void deleteAt(struct LinkedList *list, int index);
void traverse(struct LinkedList list);


int main() {
    struct LinkedList list;
    list.head = NULL;
    list.size = 0;

    insertAt(&list, 0, 10);
    insertAt(&list, 1, 20);
    insertAt(&list, 1, 15);
    insertAt(&list, 3, 25);

    printf("List after insertions: ");
    traverse(list);

    deleteAt(&list, 1);
    printf("List after deleting index 1: ");
    traverse(list);

    deleteAt(&list, 0);
    printf("List after deleting index 0: ");
    traverse(list);

    return 0;

}

//insert function
void insertAt(struct LinkedList *list, int index, int value) {
    if (index < 0 || index > list->size) {
        printf("Error: Invalid index.\n");
        return;
    }

    // Create new node
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // Insert at the beginning
    if (index == 0) {
        newNode->next = list->head;
        list->head = newNode;
    }
    else {
        // Traverse to node before insertion index
        struct Node *current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        // Link the new node
        newNode->next = current->next;
        current->next = newNode;
    }

    list->size++;

}

//deletion function
void deleteAt(struct LinkedList *list, int index) {
    if (list->size == 0) {
        printf("Error: List is empty.\n");
        return;
    }

    if (index < 0 || index >= list->size) {
        printf("Error: Invalid index.\n");
        return;
    }

    struct Node *temp;

    // Delete at beginning
    if (index == 0) {
        temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
    else {
        // Traverse to node before the one being deleted
        struct Node *current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        temp = current->next;        // Node to delete
        current->next = temp->next;  // Skip it
        free(temp);
    }

    list->size--;

}

//traversal function
void traverse(struct LinkedList list) {
    struct Node *current = list.head;

    if (current == NULL) {
        printf("[empty]\n");
        return;
    }

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

}

