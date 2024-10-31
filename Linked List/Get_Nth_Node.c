// Input:  1->10->30->14,  index = 2
// Output: 10
// Explanation: The node value at index 2 is 10


// Input:  1->32->12->10->30->14->100,  index = 8
// Output: -1
// Explanation: No such node exists at index = 8.

// C program to find the data at nth node
// recursively

#include <stdio.h>
struct Node {
    int data;
    struct Node *next;
};

// Takes head pointer of the linked list and index
// as arguments and returns data at index.
int GetNth(struct Node *head, int index) {
  
    // If the list is empty or index is out of bounds
    if (head == NULL)
        return -1;

    // If index equals 1, return node's data
    if (index == 1)
        return head->data;

    // Recursively move to the next node
    return GetNth(head->next, index - 1);
}

struct Node *createNode(int new_data) {
    struct Node *new_node =
      (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

int main() {
  
    // Create a hard-coded linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    struct Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    printf("Element at index 3 is %d\n", GetNth(head, 3));

    return 0;
}
