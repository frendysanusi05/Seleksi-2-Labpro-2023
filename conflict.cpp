#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, l, r;
    cin >> n >> m;
    vector<int> prev, after;
    vector<pair<int,int>> vect;

    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        vect.push_back({l,r});
        prev.push_back(l);
        after.push_back(r);
    }

    sort(prev.begin(), prev.end());
    sort(after.begin(), after.end());

    for (int i = 0; i < n; i++) {
        int start = upper_bound(prev.begin(), prev.end(), vect[i].second)- prev.begin() - 1;
        int end = upper_bound(after.begin(), after.end(), vect[i].first - 1) - after.begin();
        if ( i == n-1) cout << start-end << endl;
        else cout << start-end << " ";
    }
    return 0;
}