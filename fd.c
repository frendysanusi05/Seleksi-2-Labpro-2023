#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int length = n + 1;
    int arr[length];
    int freq[length+1];
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
        freq[i] = 0;
    }
    for (int i = 0; i < length; i++) {
        freq[arr[i]]++;
    }
    for (int i = 0; i < length; i++) {
        if (freq[i] > 1) printf("%d\n", i);
    }
}