class Solution {
public:
    int minMen(vector<int>& arr) {
        vector<pair<int,int>> sched; 
        
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            if(arr[i] == -1) continue;
            int start = max(0, i - arr[i]);
            int end = min(n - 1, i + arr[i]);
            sched.push_back({start, end});
        }

        sort(sched.begin(), sched.end()); 
        
        int k = sched.size();
        if(k == 0) return -1;

        int ans = 0;
        int i = 0;
        int next = -1; 
        
        while (next < n - 1) {
            int best = -1;
            
           
            while (i < k && sched[i].first-next < 2) {
                best = max(best, sched[i].second);
                i++;
            }

            if (best <= next) return -1; 

            next = best;
            ans++;
        }
        
        return ans;
    }
};