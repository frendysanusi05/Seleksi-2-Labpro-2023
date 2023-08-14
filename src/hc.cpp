#include <bits/stdc++.h>
using namespace std;

const long long MAX = 998244353;
const long long bond = 2005;

long long dp[bond][bond];
long long temp[bond][bond] = {0};

long long countWays(long long idx, long long prev, long long N, long long M, long long K) {
    if (prev < 0) {
        return 0;
    }
    if (idx == N) {
        return (prev == 0);
    }
    if (dp[idx][prev]) {
        return temp[idx][prev];
    }

    long long res = 0;
    if (idx != 0)
        res = (countWays(idx+1, prev, N, M, K) + (M-1) * countWays(idx+1, prev-1, N, M, K)) % MAX;
    else 
        res = (M * countWays(idx+1, prev, N, M, K)) % MAX;
    dp[idx][prev] = 1;
    temp[idx][prev] = res;
    return res;
}

int main() {
    long long N, M, K;
    cin >> N >> M >> K;
    cout << countWays(0,K,N,M,K) << "\n";
    return 0;
}