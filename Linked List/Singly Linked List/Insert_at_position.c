#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
typedef struct Node
{
    int data;
    struct Node* next;
} Node;

// Create a new Node
Node* createNode(int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// Insert at a specific position
Node* insert_at_position(Node* head, int value, int position)
{
    Node* new_node = createNode(value);

    // If position is 1, insert at the beginning
    if (position == 1)
    {
        new_node->next = head;
        head = new_node;
        return head;
    }

    Node* current = head;
    for (int i = 1; i < position - 1 && current != NULL; i++)
    {
        current = current->next;
    }

    // If the position is out of bounds, return the unchanged list
    if (current == NULL)
    {
        printf("Position out of bounds.\n");
        return head;
    }

    // Insert the new node at the desired position
    new_node->next = current->next;
    current->next = new_node;

    return head;
}

// Traverse the linked list and print its elements
void print_linked_list(Node* head)
{
    Node* current = head;

    printf("\nThe Linked List is: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    Node* head = createNode(11);
    head->next = createNode(12);
    head->next->next = createNode(13);

    // Insert at position 3 (after the second node) -- (head, value , position)
    head = insert_at_position(head, 15, 3);

    // Insert at position 1 (at the beginning) -- (head, value , position)
    head = insert_at_position(head, 5, 1);

    // Out of bounds (should not insert) -- (head, value , position)
    head = insert_at_position(head, 20, 10);

    // Print the updated linked list
    print_linked_list(head);

    return 0;
}
