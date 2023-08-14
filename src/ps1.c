#include <stdio.h>
#include <math.h>

#define MAX 100001

int main() {
    int b, q;
    int l, r;
    scanf("%d %d", &b, &q);
    int arr[b];
    for (int i = 0; i < b; i++) {
        scanf("%d", &arr[i]);
    }

    /* prefix sum */
    int prefsum[b+1];
    int exist[b+1];
    for (int i = 0; i < b+1; i++) {
        prefsum[i] = 0;
        exist[i] = 0;
    }
    int existSize = 0;
    for (int i = 0; i < b; i++) {
        if (!exist[arr[i]]) {
            exist[arr[i]] = 1;
            existSize++;
        }
    }

    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= sqrt(i) && j <= b; j++) {
            if (i % j == 0) {
                if (j != i / j) {
                    if (exist[j] && exist[i / j]) {
                        prefsum[i]++;
                    }
                }
            }
        }
        prefsum[i] += prefsum[i - 1];
    }

    for (int i = 0; i < q; i++) {
        scanf("%d %d", &l, &r);
        printf("%d\n", prefsum[r] - prefsum[l - 1]);
    }
    return 0;
}
