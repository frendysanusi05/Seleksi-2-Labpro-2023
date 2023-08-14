#include <stdio.h>
#include <stdbool.h>

bool isSubsetSum(int coins[], int n, int sum) {
    if (sum == 0) return true;
    if (n == 0) return false;
    if (coins[n-1] > sum) return isSubsetSum(coins, n-1, sum);
    return isSubsetSum(coins, n-1, sum) || isSubsetSum(coins, n-1, sum-coins[n-1]);
}

int main() {
    int sum, n;
    scanf("%d", &sum);
    scanf("%d", &n);
    
    int coins[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    if (isSubsetSum(coins, n, sum)) printf("YA\n");
    else printf("TIDAK\n");
    return 0;
}