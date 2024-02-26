

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void deleteByKey(struct Node **head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the key is present in the head node
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for the key to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key is not present
    if (temp == NULL) {
        printf("Key not found in the list.\n");
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);
}

void deleteByValue(struct Node **head, int value) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the value is present in the head node
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for the value to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If the value is not present
    if (temp == NULL) {
        printf("Value not found in the list.\n");
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);
}

void insertAfterKey(struct Node **head, int key, int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;

    struct Node* temp = *head;

    // Search for the node with the given key
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    // If the key is not present
    if (temp == NULL) {
        printf("Key not found in the list.\n");
        return;
    }

    // Insert the new node after the node with the given key
    new_node->next = temp->next;
    temp->next = new_node;
}

void insertAfterValue(struct Node **head, int value) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL) {
        // If the list is empty, make the new node the head
        *head = new_node;
    } else {
        struct Node* temp = *head;
        
        // Traverse to the end of the list
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Insert the new node at the end
        temp->next = new_node;
    }
}

void insertAfterValueWithSearch(struct Node **head, int searchValue, int newValue) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = newValue;

    struct Node* temp = *head;

    // Search for the node with the given searchValue
    while (temp != NULL && temp->data != searchValue) {
        temp = temp->next;
    }

    // If the searchValue is not present
    if (temp == NULL) {
        printf("Search value not found in the list.\n");
        return;
    }

    // Insert the new node after the node with the given searchValue
    new_node->next = temp->next;
    temp->next = new_node;
}

void displayList(struct Node *head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;  // Initialize an empty linked list

    insertAfterValue(&head, 10);
    insertAfterValue(&head, 20);
    insertAfterValue(&head, 30);

    printf("Original List: ");
    displayList(head);

    deleteByKey(&head, 20);
    printf("List after deleting key 20: ");
    displayList(head);

    deleteByValue(&head, 30);
    printf("List after deleting value 30: ");
    displayList(head);

    insertAfterKey(&head, 10, 25);
    printf("List after inserting 25 after key 10: ");
    displayList(head);

    insertAfterValue(&head, 35);
    printf("List after inserting value 35 at the end: ");
    displayList(head);

    insertAfterValueWithSearch(&head, 10, 45);
    printf("List after inserting 45 after value 10: ");
    displayList(head);

    return 0;
}

