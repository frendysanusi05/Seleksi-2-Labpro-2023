#include <stdio.h>
#include <math.h>
#define min(x, y) (x < y ? x : y)

int main() {
    int sum, n;
    scanf("%d", &sum);
    scanf("%d", &n);
    
    int coins[n];
    int T[sum+1];

    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    for (int i = 0; i < sum+1; i++) {
        if (i == 0) T[i] = 0;
        else T[i] = (int)INFINITY;
    }

    for (int j = 0; j < n; j++) {
        for (int i = 1; i < sum+1; i++) {
            if (i >= coins[j]) {
                T[i] = min(T[i], 1+T[i - coins[j]]);
            }
        }
    }
    if (T[sum] != 0 && T[sum] != (int)INFINITY) printf("%d\n", T[sum]);
    else printf("-1\n");
    return 0;
}