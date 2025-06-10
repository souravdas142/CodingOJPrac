#include <bits/stdc++.h>

class Solution {
  public:
    int countSetBit(int x) {
        int cnt = 0;
        while(x) {
            x = x & (x - 1);
            cnt++;
        }
        return cnt;
    }

    void sortBySetBitCount(int arr[], int n) {
        vector<pair<int,int>> vp(n);
        for(int i = 0; i < n; i++) {
            vp[i] = {countSetBit(arr[i]), arr[i]};
        }

        // Stable sort to preserve original order for equal set bit counts
        stable_sort(vp.begin(), vp.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.first > b.first;
        });

        for(int i = 0; i < n; i++) {
            arr[i] = vp[i].second;
        }
    }
};