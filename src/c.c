#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int mat[2][2];
} matrix;

matrix multiply(matrix a, matrix b) {
    matrix c;
    int i, j, k;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            c.mat[i][j] = 0;
            for (k = 0; k < 2; k++) {
                c.mat[i][j] += (a.mat[i][k] * b.mat[k][j]);
            }
        }
    }
    return c;
}

matrix matrixPower(matrix base, long long n) {
    matrix ans = { {{1, 0}, {0, 1}} };
    while (n) {
        if (n & 1)
            ans = multiply(ans, base);
        base = multiply(base, base);
        n >>= 1;
    }
    return ans;
}

long long fibonacci(int n) {
    matrix base = { {{1, 1}, {1, 0}} };
    return matrixPower(base, n).mat[0][1];
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int main() {
    int n, m, i, a, b;
    scanf("%d %d", &n, &m);
    int *prev = malloc(sizeof(int) * n);
    int *aft = malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        prev[i] = a;
        aft[i] = b;
    }

    // Sort prev and aft arrays
    qsort(prev, n, sizeof(int), cmpfunc);
    qsort(aft, n, sizeof(int), cmpfunc);

    // Do binary search for each iteration
    for (i = 0; i < n; i++) {
        int ans = 0;
        int started = binary_search(prev, n, aft[i]) - 1;
        int ended = binary_search(aft, n, prev[i] - 1);
        printf("%d ", started - ended);
    }
    return 0;
}
