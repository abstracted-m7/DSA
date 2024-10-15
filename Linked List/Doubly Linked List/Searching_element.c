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


Node* search( Node* head, int target )
{
    Node* current = head;

    while( current != NULL )
    {
        if( current->data == target )
        {
            return current;
        }
        current = current->next;
    }

    return NULL; 
}

void Traversal( Node* head )
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

    Traversal(head);

    int target = 12;
    Node* result = search(head, target);

    if (result != NULL)
    {
        printf("\nElement %d found in the linked list.\n", target);
    }
    else
    {
        printf("\nElement %d not found in the linked list.\n", target);
    }


    return 0;
}
