#include<stdio.h>
#include<stdlib.h>


//Definde the structure of a node
typedef struct Node
{
    int data;
    struct Node* next;

} Node;

// Create an Node
Node* createNode( int data )
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

//insert at beginning
Node* insert_at_beginning( Node* head , int value )
{
    Node* new_node = createNode(value);
    new_node->next = head;
    head = new_node;
    return head;
}

//Travarsal the linked list

void print_linked_list(Node* head)
{
    Node* current = head;
    printf("\nThe Linked List is : ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    Node* head = createNode(11);
    head->next = createNode(12);
    head->next->next = createNode(13);

    //store in head
    head = insert_at_beginning(head , 10);

    print_linked_list(head);

    return 0;
}