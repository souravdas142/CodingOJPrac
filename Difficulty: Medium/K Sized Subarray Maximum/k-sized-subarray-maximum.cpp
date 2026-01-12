class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        vector<int> ans;
        
        int n = arr.size();
        
        deque<pair<int,int>> dq; // number, index
        
        int j = 0;
        
        while(j<n) {
            
            if(j>=k)
                if(!dq.empty() && dq.front().second == j-k) dq.pop_front();
            
            while(!dq.empty() && dq.back().first < arr[j]) {
                dq.pop_back();
            }
            
            
            
            dq.push_back({arr[j],j});
            
            
            
            if(j>=k-1)
                ans.push_back(dq.front().first);
            
            j++;
            
        }
        
        return ans;
    }
};