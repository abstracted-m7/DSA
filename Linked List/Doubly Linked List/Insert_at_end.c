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


// Function to insert a node at the end
Node* insert_at_end(Node* head, int data)
{
    Node* newNode = createNode(data);

    // If the list is empty, the new node is the head
    if (head == NULL)
    {
        return newNode;
    }

    // Traverse to the last node
    Node* current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    // Adjust pointers to insert at the end
    current->next = newNode;
    newNode->prev = current;

    return head;  
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

    // Inserting at the end
    head = insert_at_end(head, 14); 
    traversal(head);


    return 0;
}
