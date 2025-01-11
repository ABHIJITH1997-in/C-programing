#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *top = NULL;

// Function to push an element onto the stack
void push(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Stack overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("Pushed onto the stack: %d\n", value);
}

// Function to pop an element from the stack
void pop() {
    if (!top) {
        printf("Stack underflow\n");
        return;
    }
    struct Node *temp = top;
    printf("Popped from the stack: %d\n", top->data);
    top = top->next;
    free(temp);
}

// Function to display the stack
void display() {
    if (!top) {
        printf("Empty stack\n");
        return;
    }
    struct Node *temp = top;
    printf("Stack: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, value;
    do {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}

