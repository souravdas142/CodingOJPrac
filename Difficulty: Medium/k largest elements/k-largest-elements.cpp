class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // Your code here
        priority_queue<int> pq;
        
        int n = arr.size();
        
        for(int i  = 0;i<n;i++) {
            pq.push(arr[i]);
            
        }
        
        vector<int> ans;
        
        while(k--) {
            ans.push_back(pq.top());
            pq.pop();
        }
        
        return ans;
    }
};