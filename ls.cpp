#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);
    int len_max = 0;
    deque<int> maxHeap;
    deque<int> minHeap;

    int idx_start = 0;
    int start = 0;
    int end = 0;
    long long max_sum = 0;

    bool next = true;

    while (end < N) {
        int curr = arr[end];
        while (!maxHeap.empty() && arr[maxHeap.back()] <= curr) {
            maxHeap.pop_back();
        }
        maxHeap.push_back(end);

        while (!minHeap.empty() && arr[minHeap.back()] >= curr) {
            minHeap.pop_back();
        }
        minHeap.push_back(end);

        int maxSub = arr[maxHeap.front()];
        int minSub = arr[minHeap.front()];
        if (maxSub - minSub <= M) {
            int len_curr = end - start + 1;
            if (len_curr >= len_max) {
                long long temp = 0;
                for (int i = start; i < start+len_curr; i++) {
                    temp += arr[i];
                }
    
                if (temp > max_sum) {
                    len_max = len_curr;
                    idx_start = start;
                    max_sum = temp;
                }
            }
        }
        else {
            start++;
            next = false;
            while (!maxHeap.empty() && maxHeap.front() < start) {
                maxHeap.pop_front();
            }
            while (!minHeap.empty() && minHeap.front() < start) {
                minHeap.pop_front();
            }
        }
        if (next)
            end++;
            next = true;
    }
    cout << len_max << "\n";

    for (int i = idx_start; i < idx_start + len_max; i++) {
        if (i == idx_start+len_max-1) cout << arr[i] << "\n";
        else cout << arr[i] << " ";
    }
    return 0;
}