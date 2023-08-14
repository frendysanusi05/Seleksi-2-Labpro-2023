#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAX = 1e5+1;
vector<vector<int>> adj(MAX);
vector<int> visited(MAX);
int timee[MAX];
int low [MAX]; // minimum of time
int timer = 0;
int cnt = 0;

void dfs(int i, int parent = -1) {
    visited[i] = true;
    timer++;
    timee[i] = timer;
    low[i] = timer;

    for (int x : adj[i]) {
        if (x == parent) {
            continue;
        }
        if (visited[x]) {
            low[i] = min(low[i], timee[x]);
        }
        else {
            dfs(x, i);
            low[i] = min(low[i], low[x]);
            if (low[x] > timee[i]) {
                cnt++;
            }
        }
    }
}

int32_t main() {
    int n, m, k;
    int u, v;
    cin >> n >> m >> k;

    visited.assign(n, 0);

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // use bridges
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    cnt -= k;
    if (cnt < 0) cnt = 0;
    cout << cnt << endl;
    return 0;
}