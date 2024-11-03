// Input: head: 1->2->1->1->2->1
// Output: true
// Explanation: The given linked list is 1->2->1->1->2->1 , which is a palindrome and Hence, the output is true.


// Input: head: 1->2->3->4
// Output: false
// Explanation: The given linked list is 1->2->3->4, which is not a palindrome and Hence, the output is false.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(int stack[], int* top, int value) {
    stack[++(*top)] = value;
}

// Function to pop an element from the stack
int pop(int stack[], int* top) {
    return stack[(*top)--];
}

// Function to check if the linked list is palindrome
bool isPalindrome(struct Node* head) {
    struct Node* currNode = head;
    
    // Stack to store elements of the linked list
    int stack[100];
    int top = -1;

    // Push all elements of the list onto the stack
    while (currNode != NULL) {
        push(stack, &top, currNode->data);
        currNode = currNode->next;
    }

    // Iterate over the list again and check by popping from the stack
    while (head != NULL) {
        int c = pop(stack, &top);

        // Check if data is not the same as the popped element
        if (head->data != c) {
            return false;
        }
        
        head = head->next;
    }

    return true;
}

// Main function
int main() {
    // Linked list : 1->2->3->2->1
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(1);

    bool result = isPalindrome(head);

    if (result)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
