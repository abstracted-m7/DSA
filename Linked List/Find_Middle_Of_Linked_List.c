// Input: linked list: 1->2->3->4->5
// Output: 3 
// Explanation: There are 5 nodes in the linked list and there is one middle node whose value is 3.


// Input: linked list = 10 -> 20 -> 30 -> 40 -> 50 -> 60
// Output: 40
// Explanation: There are 6 nodes in the linked list, so we have two middle nodes: 30 and 40, but we will return the second middle node which is 40.



#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Helper function to find length of linked list
int getLength(struct Node* head) {

    // Variable to store length
    int length = 0;

    // Traverse the entire linked list and increment length
    // by 1 for each node
    while (head) {
        length++;
        head = head->next;
    }

    // Return the number of nodes in the linked list
    return length;
}

// Function to find the middle element of the linked list
int getMiddle(struct Node* head) {

    // Finding length of the linked list
    int length = getLength(head);

    // Traverse till we reach half of the length
    int mid_index = length / 2;
    while (mid_index--) {
        head = head->next;
    }

    // Head now will be pointing to the middle element
    return head->data;
}

struct Node* createNode(int x) {
    struct Node* newNode
        = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

int main() {

    // Create a hard-coded linked list:
    // 10 -> 20 -> 30 -> 40 -> 50 -> 60 
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);
    head->next->next->next->next->next = createNode(60);

    printf("%d\n", getMiddle(head));

    return 0;
}

