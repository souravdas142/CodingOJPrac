class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto e: arr) pq.push(e);
        int ans = 0;
        while(pq.size()>1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            int sum = a+b;
            ans+=sum;
            pq.push(sum);
        }
        return ans;
    }
};