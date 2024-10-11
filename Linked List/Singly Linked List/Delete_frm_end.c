#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

//create an node
Node* createNode(int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

//Delete from end
Node* delete_frm_end(Node* head)
{
    //blank linkedlist
    if (head == NULL)
    {
        return NULL;
    }

    //only one element present
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    //main funtionality to delete the last node
    Node* second_last = head;
    while (second_last->next->next != NULL)
    {
        second_last = second_last->next;
    }

    free(second_last->next);
    second_last->next = NULL;
    
    return head;    
}

//print linkedlist
void travarse(Node* head)
{
    Node* current = head;

    printf("\nThe Linkedlist is : ");
    while (current != NULL)
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
    head->next->next->next = createNode(13);

    head = delete_frm_end(head);

    travarse(head);

    return 0;
}