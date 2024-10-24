#include <stdio.h>

#define MAX_SIZE 100

// Function to find the union of two sets
void setUnion(int setA[], int sizeA, int setB[], int sizeB, int unionSet[], int *sizeUnion) {
    int i, j;
    
    // Add all elements of set A to unionSet
    for (i = 0; i < sizeA; i++) {
        unionSet[*sizeUnion] = setA[i];
        (*sizeUnion)++;
    }

    // Add elements of set B to unionSet if they are not already present
    for (i = 0; i < sizeB; i++) {
        int found = 0;
        for (j = 0; j < *sizeUnion; j++) {
            if (setB[i] == unionSet[j]) {
                found = 1; // Element is already in unionSet
                break;
            }
        }
        if (!found) {
            unionSet[*sizeUnion] = setB[i];
            (*sizeUnion)++;
        }
    }
}

// Function to print the set
void printSet(int set[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", set[i]);
    }
    printf("\n");
}

int main() {
    int setA[] = {1, 2, 3, 4, 5};
    int setB[] = {4, 5, 6, 7, 8};
    int unionSet[MAX_SIZE];
    int sizeUnion = 0;

    setUnion(setA, 5, setB, 5, unionSet, &sizeUnion);

    printf("Union of Set A and Set B: ");
    printSet(unionSet, sizeUnion);

    return 0;
}
