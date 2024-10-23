#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;


Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}


void makeCircular(Node* head)
{
    if (head == NULL) return;

    Node* tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    // Connect end points
    tail->next = head;
    head->prev = tail;
}

int search(Node* head, int target)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return false;
    }

    Node* current = head;
    do
    {
        if (current->data == target)
        {
            return true;
        }
        current = current->next;
    } while (current != head);

    return false;
}

void traversal(Node* head)
{
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    Node* current = head;
    printf("The circular linked list is: ");

    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
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

    int target = 12;

    if (search(head, target))
    {
        printf("\nElement %d found in the circular linked list.\n\n", target);
    } 
    else
    {
        printf("\nElement %d not found in the circular linked list.\n\n", target);
    }

    return 0;
}
