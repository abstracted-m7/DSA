// Input  : Stack[] = [1, 2, 3, 4, 5]
// Output : Stack[] = [1, 2, 4, 5]


// Input  : Stack[] = [1, 2, 3, 4, 5, 6]
// Output : Stack[] = [1, 2, 4, 5, 6]

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

// Define the stack structure
struct Stack {
    int top;
    char arr[MAX];
};

// Function to initialize the stack
void initStack(struct Stack* st) {
    st->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* st) {
    return st->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* st, char value) {
    if (st->top < MAX - 1) {
        st->arr[++(st->top)] = value;
    }
}

// Function to pop an element from the stack
char pop(struct Stack* st) {
    if (!isEmpty(st)) {
        return st->arr[(st->top)--];
    }
    return '\0';  // Return null character if stack is empty
}

// Function to get the top element of the stack
char top(struct Stack* st) {
    if (!isEmpty(st)) {
        return st->arr[st->top];
    }
    return '\0';  // Return null character if stack is empty
}

int main() {
    struct Stack st;
    initStack(&st);

    // Push elements onto the stack
    push(&st, '1');
    push(&st, '2');
    push(&st, '3');
    push(&st, '4');
    push(&st, '5');
    push(&st, '6');
    push(&st, '7');

    char v[MAX];
    int n = 0;

    // Pop elements from the stack and store in array v
    while (!isEmpty(&st)) {
        v[n++] = top(&st);
        pop(&st);
    }

    int target;
    if (n % 2 == 0) {
        target = n / 2;
    } else {
        target = (int)ceil(n / 2.0);
    }

    // Push elements back to the stack, skipping the middle element
    for (int i = 0; i < n; i++) {
        if (i == target) continue;
        push(&st, v[i]);
    }

    printf("Printing stack after deletion of middle: ");
    while (!isEmpty(&st)) {
        char p = top(&st);
        pop(&st);
        printf("%c ", p);
    }

    return 0;
}
