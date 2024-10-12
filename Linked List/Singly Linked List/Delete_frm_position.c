#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a new node
Node* createNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Delete from a specific position
Node* delete_from_position(Node* head, int position) {
    // If the linked list is empty
    if (head == NULL) {
        printf("List is empty, cannot delete.\n");
        return NULL;
    }

    // If the position is 0, delete the head
    if (position == 0) {
        Node* temp = head;
        head = head->next; // Move head to the next node
        free(temp);        // Free the old head
        return head;
    }

    // Find the node before the position to delete
    Node* current = head;
    for (int i = 0; current != NULL && i < position - 1; i++) {
        current = current->next;
    }

    // If the current node is NULL or the next node is NULL, position is out of bounds
    if (current == NULL || current->next == NULL) {
        printf("Position out of bounds.\n");
        return head;
    }

    // Node current->next is the node to be deleted
    Node* temp = current->next; 
    current->next = current->next->next; // Unlink the node from the linked list
    free(temp); // Free memory
    return head;    
}

// Print linked list
void traverse(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {

    Node* head = createNode(10);
    head->next = createNode(11);
    head->next->next = createNode(12);
    head->next->next->next = createNode(13);

    printf("\nOriginal linked list: ");
    traverse(head);

    // Delete node at position 2 (0-based index)
    int position = 2;
    head = delete_from_position(head, position);

    printf("\nUpdated linked list after deleting node at position %d: ", position + 1 );
    traverse(head);

    return 0;
}
