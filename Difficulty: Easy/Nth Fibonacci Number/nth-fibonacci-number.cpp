// User function Template for C++
class Solution {
  public:
    int fibs(int n, vector<int>& dp) {
        
        if(n<=1) return n;        
        
        if(dp[n]!=-1) return dp[n];
        
        return dp[n] = fibs(n-1,dp)+fibs(n-2,dp);
    }
    int nthFibonacci(int n) {
        // code here
        vector<int> dp(n+1,-1);
        return fibs(n,dp);
    }
};