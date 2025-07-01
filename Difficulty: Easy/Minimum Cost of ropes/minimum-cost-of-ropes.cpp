class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int n = arr.size();
         priority_queue<int, vector<int> , greater<int>> pq;
        
        for(auto e: arr) {
            pq.push(e);
        }
        
        int ans = 0;
        
        while(pq.size()>1) {
            int a = pq.top();
            ans+=a;
            pq.pop();
            int b = pq.top();
            ans+=b;
            pq.pop();
            pq.push(a+b);
            
        }
        
        return ans;
    }
};