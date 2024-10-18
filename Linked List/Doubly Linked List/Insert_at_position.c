
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


// Function to insert a node at a given position
Node* insert_at_position(Node* head, int data, int position)
{
    Node* newNode = createNode(data);

    // If inserting at the beginning (position 1)
    if (position == 1)
    {
        newNode->next = head;
        if (head != NULL) head->prev = newNode;
        return newNode;  // New node becomes the new head
    }

    Node* current = head;
    int count = 1;

    // Traverse to the node just before the desired position
    while (current != NULL && count < position - 1)
    {
        current = current->next;
        count++;
    }

    // If the position is beyond the current list length, insert at the end
    if (current == NULL)
    {
        return head;  // Position is invalid
    }

    // Insert the new node in between the nodes
    newNode->next = current->next;
    newNode->prev = current;
    
    if (current->next != NULL)
    {
        current->next->prev = newNode;
    }

    current->next = newNode;

    return head;  // Head remains unchanged
}

void traversal( Node* head )
{
    Node* current = head;

    printf("\nThe forward traversal is : ");
    while( current != NULL )
    {
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
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

    // Inserting at position 3 - (head , value , index)
    head = insert_at_position(head, 15, 3);  
    traversal(head);

    // Inserting at the beginning (position 1) - (head , value , index)
    head = insert_at_position(head, 9, 1); 
    traversal(head);

    // out of bound
    head = insert_at_position(head, 16, 10);
    traversal(head);

    return 0;
}
