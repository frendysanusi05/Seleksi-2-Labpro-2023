#include <iostream>
#include <vector>
using namespace std;

#define int long long

int32_t main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    vector<int> tukar(Q);
    for (int i = 0; i < Q; i++) {
        cin >> tukar[i];
    }

    for (int i = 0; i < Q; i++) {
        vector<int> temp(tukar[i]);
        for (int j = 0; j < tukar[i]; j++) {
            cin >> temp[j];
        }

        for (int k = 0; k < tukar[i]/2; k++) {
            int swap = arr[temp[k]-1];
            arr[temp[k]-1] = arr[temp[tukar[i]-1-k]-1];
            arr[temp[tukar[i]-1-k]-1] = swap;
        }

        if (tukar[i] % 2 != 0) {
            arr.erase(arr.begin() + temp[tukar[i]/2]-1);
        }
    }

    if (arr.size() == 0) {
        cout << "Tidak ada pemenang\n";
    } else {
        cout << arr.size() << " " << arr.front() << endl;
    }
    
    return 0;
}
