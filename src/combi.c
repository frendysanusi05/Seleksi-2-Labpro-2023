#include <stdio.h>
#include <stdlib.h>

void getCombinationsUtil(int a[], int sum, int currIndex, int result[100][100], int curr[], int* size) {
    if (sum == 0) {
        for (int i = 0; i < currIndex; i++) {
            result[*size][i] = curr[i];
        }
        (*size)++;
        return;
    }
    else if (sum < 0 || currIndex == *size) {
        return;
    }
    else {
        curr[currIndex] = a[currIndex];
        getCombinationsUtil(a, sum - a[currIndex], currIndex, result, curr, size);
        curr[currIndex] = 0;
        getCombinationsUtil(a, sum, currIndex + 1, result, curr, size);
    }
}

int** getCombinations(int a[], int sum, int* numCombinations) {
    int** result = (int**)malloc(100 * sizeof(int*));
    for (int i = 0; i < 100; i++) {
        result[i] = (int*)malloc(100 * sizeof(int));
    }
    int* curr = (int*)malloc(100 * sizeof(int));
    int index = 0;
    *numCombinations = 0;
    getCombinationsUtil(a, sum, index, result, curr, numCombinations);
    free(curr);
    return result;
}

int main() {
    int a[] = {1, 2, 3};
    int sum = 3;
    int numCombinations;
    int** combinations = getCombinations(a, sum, &numCombinations);

    printf("All combinations:\n");
    for (int i = 0; i < numCombinations; i++) {
        for (int j = 0; j < 100; j++) {
            if (combinations[i][j] != 0) {
                printf("%d ", combinations[i][j]);
            }
            else {
                break;
            }
        }
        printf("\n");
    }

    for (int i = 0; i < 100; i++) {
        free(combinations[i]);
    }
    free(combinations);

    return 0;
}
