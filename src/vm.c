#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    char arr[n];
    int freq[26];
    for (int i = 0; i < n; i++) {
        scanf(" %c", &arr[i]);
    }
    for (int i = 0; i < 26; i++) {
        freq[i] = 0;
    }
    int max = 0;
    int vote;
    for (int i = 0; i < n; i++) {
        freq[arr[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (freq[i] > max) {
            max = freq[i];
            vote = i;
        }
    }
    printf("%c\n", vote + 'a');
    return 0;
}