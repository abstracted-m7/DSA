
#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* next;
} Node;


//Function for add nodes
Node* createNode(int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

//Find Length of the linkedlist
void lengthFind(Node* head)
{
    int length = 0;

    Node* current = head;
    while (current != NULL) 
    {
        length ++;
        current = current->next;
    }

    printf("\nThe length of the linked list : %d.",length);
}

int main()
{
    Node* head = createNode(11);
    head->next = createNode(12);
    head->next->next = createNode(13);
    head->next->next->next = createNode(15);

    lengthFind(head);
}