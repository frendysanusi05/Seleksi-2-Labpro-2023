#include <stdio.h>

long long count(int N, int M, int K) {
    int dp[N+1][2005];
    for (int i = 0; i < N+1; i++) {
        for (int j = 0; j < 2005; j++) {
            dp[i][j] = 0;
        }
    }

    for (int cnt = 0; cnt <= K; cnt++) {
        if (cnt == K) dp[N][cnt] = 1;
        else dp[N][cnt] = 0;
    }

    // bottom-up approach
    for (int idx = N-1; idx > 0; idx--) {
        for (int cnt = 0; cnt <= K; cnt++) {
            long long res = 0;
            res += dp[idx+1][cnt];
            if (cnt + 1 <= K)
                res += (M-1) * dp[idx+1][cnt+1];
            dp[idx][cnt] = res;
        }
    }

    return M * dp[1][0];
}

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    printf("%lld\n", count(N,M,K) % 998244353);
    return 0;
}