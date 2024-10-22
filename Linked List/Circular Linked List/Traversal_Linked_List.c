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

void traversal(Node* head)
{
    if (head == NULL)
    {
        printf("\nThe list is empty.\n");
        return;
    }

    Node* current = head;
    printf("\nThe circular linked list is : ");
    do
    {
        printf("%d ", current->data);
        current = current->next;
        
    } while (current != head);

    printf("\n");
}

// Function to make the list circular
void makeCircular(Node* head)
{
    if (head == NULL) return;

    Node* tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    //connect end points
    tail->next = head;
    head->prev = tail;
}

int main()
{
    // Creating nodes
    Node* head = createNode(10);
    Node* second = createNode(11);
    Node* third = createNode(12);
    Node* fourth = createNode(13);

    // Linking nodes
    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;
    
    third->next = fourth;
    fourth->prev = third;

    // Making the list circular
    makeCircular(head);

    // Printing the circular linked list
    traversal(head);

    return 0;
}
