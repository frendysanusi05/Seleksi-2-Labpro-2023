#include <bits/stdc++.h>
using namespace std;

#define int long long

bool isValid(int arrPos[], int n, int cup, int mid) {
    int cnt = 1;
    int first = arrPos[0];

    for (int i = 1; i < n; i++) {
        if (arrPos[i]-first >= mid) {
            cnt++;
            first = arrPos[i];
        }
        if (cnt == cup) return true;
    }
    return false;
}

int32_t main() {
    int n, cup;
    cin >> n >> cup;
    int arrPos[n];
    for (int i = 0; i < n; i++) {
        cin >> arrPos[i];
    }
    sort(arrPos, arrPos+n);
    
    int low = 1;
    int high = arrPos[n-1] - arrPos[0];
    int mid;
    int res;
    while (low <= high) {
        mid = (low + high) / 2;
        if (isValid(arrPos, n, cup, mid)) {
            res = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << res << endl;
    return 0;
}