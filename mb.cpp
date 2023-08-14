#include <bits/stdc++.h>
using namespace std;

#define MAX (int)1e6+1

int main() {
    int N, M;
    cin >> N >> M;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    int dp[MAX] = {0};
    dp[0] = 1;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= M; j++) {
            if (j - arr[i] >= 0) {
                dp[j] = (dp[j] + dp[j - arr[i]]) % (int)(1e9+ 7);
            }
        }
    }
    cout << dp[M] << "\n";
    return 0;
}