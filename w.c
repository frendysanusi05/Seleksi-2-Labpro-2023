#include <stdio.h>
#include <string.h>

int main() {
    long long N;
    scanf("%lld", &N);
    char arr[N][100000];

    int freq[26];
    for (int i = 0; i < 26; i++) {
        freq[i] = 0;
    }

    for (long long i = 0; i < N; i++) {
        scanf("%s", &arr[i]);
    }

    for (long long i = 0; i < N; i++) {
        for (long long j = 0; j < strlen(arr[i]); j++) {
            freq[arr[i][j] - 'a']++;
        }
    }

    long long cnt = 0;
    while (freq['w' - 'a'] != 0 && freq['a' - 'a'] != 0 && freq['d' - 'a'] != 0 && freq['u' - 'a'] != 0 && freq['h' - 'a'] != 0) {
        freq['w'-'a']--;
        freq['a'-'a']--;
        freq['d'-'a']--;
        freq['u'-'a']--;
        freq['h'-'a']--;
        cnt++;
    }
    printf("%lld\n", cnt);
    return 0;
}