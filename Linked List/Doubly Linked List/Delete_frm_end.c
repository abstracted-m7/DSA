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

// Function to delete the node from the end
Node* delete_frm_end(Node* head)
{
    if (head == NULL)
    {
        printf("\nThe list is empty, nothing to delete.\n");
        return NULL;
    }

    if (head->next == NULL)
    {
        //only one element present
        free(head);
        return NULL;
    }

    Node* current = head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    // Adjust the second-to-last node's next pointer to NULL
    current->prev->next = NULL;

    free(current);  // Free the memory of the last node
    return head; 
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

    // Deleting from the end
    head = delete_frm_end(head);  // Deletes node with data 13
    traversal(head);

    // Deleting again from the end
    head = delete_frm_end(head);  // Deletes node with data 12
    traversal(head);

    // Deleting all nodes until the list is empty
    head = delete_frm_end(head);  // Deletes node with data 11
    traversal(head);



    return 0;
}
