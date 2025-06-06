class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        int n = arr.size();
        int running = 0;
        int sum = 0;
        int cnt = 0;
        for(int i = 0;i<n;i++) {
            sum+=i;
            running += arr[i];
            if(sum==running) cnt++;
        }

        return cnt;

    }
};