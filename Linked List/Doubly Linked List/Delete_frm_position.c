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

    while( current != NULL )
    {
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to get the length of the doubly linked list
int getLength(Node* head)
{
    int length = 0;
    Node* current = head;

    while (current != NULL)
    {
        length++;
        current = current->next;
    }

    return length;
}

// Function to delete the node from a specific position
Node* delete_frm_position(Node* head, int position)
{
    if (head == NULL)
    {
        printf("\nThe list is empty, nothing to delete.\n");
        return NULL;
    }

    int length = getLength(head);
    if (position < 1 || position > length)
    {
        printf("\nInvalid position! Please provide a valid position (1-%d).\n", length);
        return head;
    }

    if (position == 1)
    {
        // Deleting from the beginning
        Node* temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }

    Node* current = head;
    // Traverse to the node at the given position
    for (int i = 1; i < position; i++)
    {
        current = current->next;
    }

    // Adjust the previous and next pointers
    if (current->prev != NULL)
    {
        current->prev->next = current->next;
    }
    if (current->next != NULL)
    {
        current->next->prev = current->prev;
    }

    free(current);  // Free the memory of the node to be deleted
    return head;    // Return the (potentially updated) head
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

    printf("\nThe linked list is : ");
    traversal(head);

    // Deleting node at position 3 (head , position 3)
    printf("\nAfter delete 3rd positions linked list : ");
    head = delete_frm_position(head, 3);
    traversal(head);


    return 0;
}
