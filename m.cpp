#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAX = 2e5+1;
// vector<vector<int>> adj(MAX);
set<int> adj[MAX];
vector<int> visited(MAX);

void dfs(int i) {
    visited[i] = 1;
    for (int x : adj[i]) {
        if (!visited[x]) {
            dfs(x);
        }
    }
}

bool checkCycle(int i, int par) {
    visited[i] = 1;
    for (int x : adj[i]) {
        if (visited[x]) {
            if (x != par) {
                return true;
            }
        }
        else {
            checkCycle(x, i);
        }
    }
    return false;
}

int32_t main() {
    int N, x;
    cin >> N;
    visited.assign(MAX, 0);
    for (int i = 0; i < N; i++) {
        cin >> x;
        adj[i+1].insert(x);
        adj[x].insert(i+1);
    }

    int cnt_max = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i);
            cnt_max++;
        }
    }

    visited.assign(MAX, 0);
    int cycle = 0, not_cycle = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            if (checkCycle(i, -1)) cycle++;
            else not_cycle++;
        }
    }
    cout << cycle + (not_cycle > 0) << " " << cnt_max << endl;
    return 0;
}