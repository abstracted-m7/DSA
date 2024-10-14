
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



// Function to find the length of the doubly linked list
int Length(Node* head)
{
    int length = 0;
    Node* current = head;

    // Traverse the list and count nodes
    while (current != NULL)
    {
        length++;
        current = current->next;
    }

    return length;
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


    // Calculate the length of the list
    int length = Length(head);
    printf("The length of the doubly linked list is: %d\n", length);

    return 0;
}
