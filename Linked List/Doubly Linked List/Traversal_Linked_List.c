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

void forwardTraversal( Node* head )
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

void backwardTraversal( Node* tail )
{
    Node* current = tail;

    printf("\nThe backward Traversal is : ");
    while ( current != NULL )
    {
        printf("%d ",current->data);
        current = current->prev;
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

    forwardTraversal(head);
    backwardTraversal(fourth);

    free(head);
    free(second);
    free(third);
    free(fourth);

    return 0;
}