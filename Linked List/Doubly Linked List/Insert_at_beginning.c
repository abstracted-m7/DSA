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


// Function to insert a node at the beginning
Node* insert_at_beginning(Node* head, int data)
{
    Node* newNode = createNode(data);

    // If the list is empty, the new node is the head
    if (head == NULL)
    {
        return newNode;
    }

    // Otherwise, adjust pointers
    newNode->next = head;
    head->prev = newNode;

    // Return the new head of the list
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


    head = insert_at_beginning(head, 9); 
    traversal(head);

    return 0;
}
