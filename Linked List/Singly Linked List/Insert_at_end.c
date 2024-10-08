
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;


//Create an node
Node* createNode(int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

//Add an element at the end
Node* insert_at_end(Node* head, int data)
{
    Node* new_Node = createNode(data);

    if (head == NULL)
    {
        return new_Node;
    }

    //find last element
    Node* current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    //link the new node with the current last node.
    current->next = new_Node;
    
    return head;
}


//Travarse the linkedlist
void print_linked_list(Node* head)
{
    Node* current = head;

    printf("\nThe Linked list is : ");
    while ( current != NULL)
    {
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
    
}

int main()
{
    Node* head = createNode(10);
    head->next = createNode(11);
    head->next->next = createNode(12);

    head = insert_at_end(head , 13);

    print_linked_list(head);

    return 0;
}