#include <stdio.h>

#define UNIVERSE_SIZE 8  // Size of the universe (0 to 7)

// Display a set represented by a bit string
void displaySet(int set) {
    printf("{ ");
    for (int i = 0; i < UNIVERSE_SIZE; i++) {
        if (set & (1 << i)) {
            printf("%d ", i);
        }
    }
    printf("}\n");
}

// Union of two sets
int unionSet(int set1, int set2) {
    return set1 | set2;
}

// Intersection of two sets
int intersectionSet(int set1, int set2) {
    return set1 & set2;
}

// Difference of two sets (set1 - set2)
int differenceSet(int set1, int set2) {
    return set1 & ~set2;
}

int main() {
    int set1 = 0, set2 = 0, choice, element;

    printf("Set Operations using Bit Strings\n");
    printf("Enter elements for Set 1 (0 to 7, -1 to stop):\n");
    while (1) {
        scanf("%d", &element);
        if (element == -1) break;
        if (element >= 0 && element < UNIVERSE_SIZE) {
            set1 |= (1 << element);
        } else {
            printf("Invalid element. Try again.\n");
        }
    }

    printf("Enter elements for Set 2 (0 to 7, -1 to stop):\n");
    while (1) {
        scanf("%d", &element);
        if (element == -1) break;
        if (element >= 0 && element < UNIVERSE_SIZE) {
            set2 |= (1 << element);
        } else {
            printf("Invalid element. Try again.\n");
        }
    }

    printf("\nSet 1: ");
    displaySet(set1);
    printf("Set 2: ");
    displaySet(set2);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Union\n");
        printf("2. Intersection\n");
        printf("3. Difference (Set1 - Set2)\n");
        printf("4. Difference (Set2 - Set1)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Union: ");
                displaySet(unionSet(set1, set2));
                break;
            case 2:
                printf("Intersection: ");
                displaySet(intersectionSet(set1, set2));
                break;
            case 3:
                printf("Difference (Set1 - Set2): ");
                displaySet(differenceSet(set1, set2));
                break;
            case 4:
                printf("Difference (Set2 - Set1): ");
                displaySet(differenceSet(set2, set1));
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

