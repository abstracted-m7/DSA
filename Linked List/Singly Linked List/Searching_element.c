#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

//Function to create new node
Node* createNode(int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
} 



// Function to search for a value in the Linked List
bool searchLinkedList(Node* head, int target)
{
    // Traverse the Linked List
    while (head != NULL) {

        if (head->data == target) 
        {
            return true;
        }

        head = head->next;
    }

    return false; 
}

int main()
{
    // Create a new node with data 10
    Node* head = createNode(10);
    head->next = createNode(11);
    head->next->next = createNode(15);

    int target = 11;

    int result = searchLinkedList(head , target);

    if (result)
    {
        printf("\nElement is in the linked list..!!");
    }
    else
    {
        printf("\nElement is not in the linked list...!!");
    }
    
    return 0;
}