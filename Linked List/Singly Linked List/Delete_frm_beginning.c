#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* createNode(int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

Node* delete_frm_beginning(Node* head)
{
    if ( head == NULL )
    {
        return NULL;
    }

    Node* temp = head;
    head = head->next;

    free(temp);

    return head; 
}

void travarsel(Node* head)
{
    Node* current = head;
    printf("\nThe linked list is : ");
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

    head = delete_frm_beginning(head);

    travarsel(head);

    return 0;
}