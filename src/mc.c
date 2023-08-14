#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define min(x,y) (x < y ? x : y)

int memo[1001][10001];

int minCntSubsetSum(int coins[], int n, int sum) {
    if (sum == 0) return 0;
    if (n == 0) return (int)INFINITY;

    /* Cek di memo */
    if (memo[n][sum] != -1) return memo[n][sum];

    if (coins[n-1] > sum) memo[n][sum] =  minCntSubsetSum(coins, n-1, sum);
    else memo[n][sum] = min(minCntSubsetSum(coins, n-1, sum), 1+minCntSubsetSum(coins, n-1, sum-coins[n-1]));
    return memo[n][sum];
}

int main() {
    int sum, n;
    scanf("%d", &sum);
    scanf("%d", &n);
    
    int coins[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    /* Inisialisasi memo */
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 10001; j++) {
            memo[i][j] = -1;
        }
    }

    int res = minCntSubsetSum(coins, n, sum);
    if (res == 0 || res == (int)INFINITY) printf("-1");
    else printf("%d", res);
    printf("\n");
    return 0;
}