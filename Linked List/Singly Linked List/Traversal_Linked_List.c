#include <stdio.h>
#include <stdlib.h> //for malloc

// Definition of a Node in a singly linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new Node
Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to traverse the linked list
void traverse_Linked_List(Node* head) {
    Node* current = head;

    printf("\nThe Linked List is : ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    // Creating nodes
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);

    //function calling to print
    traverse_Linked_List(head);

    return 0;
}
