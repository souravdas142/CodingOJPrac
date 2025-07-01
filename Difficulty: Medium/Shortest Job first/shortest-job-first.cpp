// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        int n = bt.size();
        int ans = 0;
        sort(bt.begin(), bt.end());
        int wt = bt[0];
        
        for(int i = 1;i<n;i++) {
            ans+=wt;
            wt+=bt[i];
            
        }
        return ans/n;

        
    }
};