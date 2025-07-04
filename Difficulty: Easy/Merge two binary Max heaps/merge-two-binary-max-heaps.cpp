// User function Template for C++

class Solution {
  public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        if(n<m) {
            return mergeHeaps(b,a,m,n);
        }
        priority_queue<int> pq;
        for(int i = 0;i<n;i++) {
            pq.push(a[i]);
        }
        for(int i = 0;i<m;i++) {
            pq.push(b[i]);
        }
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};