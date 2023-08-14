#include <stdio.h>
#include <math.h>

// void printarray(int arr[], int size)
// {
//     int i,j;
//     for(i=0; i<size; i++)
//     {
//         printf("%d\t",arr[i]);
//     }
//     printf("\n");
// }

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(char* op, int* arr, int start, int end, long long* min) {
    if (start == end) {
        // printarray(arr, end+1);
        long long temp = arr[0];
        for (int i = 0; i < 3; i++) {
            // printf("%c\n", op[i]);
            if (op[i] == '*') temp *= arr[i+1];
            else temp += arr[i+1];
            // printf("%lld\n", temp);
        }
        if (temp < *min) *min = temp;
        // special approach
        if (op[0] == '+' && (op[1] == '*') && op[2] == '+') temp = (arr[0] + arr[1]) + (arr[2] * arr[3]);
        else if (op[0] == '*' && (op[1] == '*') && op[2] == '+') temp = (arr[0] * arr[1]) + (arr[2] * arr[3]);
        else if (op[0] == '+' && (op[1] == '*') && op[2] == '*') temp = arr[0] * (arr[1] + arr[2]) * arr[3];
        else if (op[0] == '+' && op[1] == '+' && op[2] == '*') temp = (arr[0] + arr[1]) * (arr[2] + arr[3]);
        if (temp < *min) *min = temp;
        return;
    }
    int i;
    for (i = start; i <= end; i++) {
        swap((arr + i), (arr + start));
        permutation(op, arr, start + 1, end, min);
        swap((arr + i), (arr + start));
    }
}

int main() {
    int arr[4];
    char op[3];
    long long min = (long long)INFINITY;
    for (int i = 0; i < 4; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 3; i++) {
        scanf(" %c", &op[i]);
    }
    permutation(op, arr, 0, 3, &min);
    printf("%lld\n", min);
    return 0;
}