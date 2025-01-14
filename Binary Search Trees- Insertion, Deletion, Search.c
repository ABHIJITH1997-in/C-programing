#include <stdio.h>
#include <stdlib.h>

// Structure of a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a value into the tree
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Search for a value in the tree
int search(struct Node* root, int value) {
    if (root == NULL) {
        return 0; // Value not found
    }
    if (root->data == value) {
        return 1; // Value found
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    return search(root->right, value);
}

// Print the tree in sorted order
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    printf("Welcome to the Binary Search Tree Program!\n");
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert a number\n");
        printf("2. Search for a number\n");
        printf("3. Display all numbers (sorted)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the number to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("%d has been added to the tree.\n", value);
        } else if (choice == 2) {
            printf("Enter the number to search: ");
            scanf("%d", &value);
            if (search(root, value)) {
                printf("%d is in the tree.\n", value);
            } else {
                printf("%d is not in the tree.\n", value);
            }
        } else if (choice == 3) {
            printf("Numbers in the tree (sorted): ");
            inorder(root);
            printf("\n");
        } else if (choice == 4) {
            printf("Thank you for using the program. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

