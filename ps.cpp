#include <bits/stdc++.h>
using namespace std;

#define MAX (int)1e5+1

int main() {
    int b, q;
    int l, r;
    cin >> b >> q;
    int arr[b];
    for (int i = 0; i < b; i++) {
        cin >> arr[i];
    }

    /* prefix sum */
    int prefsum[MAX] = {0};
    set<int> exist;
    for (int i = 0; i < b; i++) {
        exist.insert(arr[i]);
    }

    for (int i = 1; i <= b; i++) {
        for (int j = 1; j <= sqrt(i); j++) {
            if (i % j == 0){
                if (j != i/j) {
                    if (exist.find(j) != exist.end() && exist.find(i/j) != exist.end()){
                        prefsum[i]++;
                    }
                }
            }
        }
        prefsum[i] += prefsum[i - 1];
    }

    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        cout << prefsum[r]-prefsum[l-1] << "\n";
    }
    return 0;
}