#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode( int data )
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void traversal( Node* head )
{
    Node* current = head;

    printf("\nThe linked list is : ");
    while( current != NULL )
    {
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to delete the node from the beginning
Node* delete_frm_beginning(Node* head)
{
    if (head == NULL)
    {
        printf("\nThe list is empty, nothing to delete.\n");
        return NULL;
    }

    Node* temp = head;  // Store the current head in temp
    head = head->next;  // Move the head to the next node

    if (head != NULL)
    {
        head->prev = NULL;  // Set the new head's prev to NULL
    }

    free(temp);  // Free the memory of the old head
    return head; // Return the new head
}

int main()
{
    Node* head = createNode(10);
    Node* second = createNode(11);
    Node* third = createNode(12);
    Node* fourth = createNode(13);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;
    
    third->next = fourth;
    fourth->prev = third;

    traversal(head);

    // Deleting from the beginning
    head = delete_frm_beginning(head);  // Deletes node with data 10
    traversal(head);

    // Deleting again from the beginning
    head = delete_frm_beginning(head);  // Deletes node with data 11
    traversal(head);

    return 0;
}
