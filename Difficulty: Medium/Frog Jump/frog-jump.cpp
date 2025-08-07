class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n+1,0);
        dp[1] = dp[0] + abs(height[1]-height[0]);
        
        for(int i  = 2;i<n;i++) {
            dp[i] = min(
                
                dp[i-1]+abs(height[i-1]-height[i]),
                dp[i-2]+abs(height[i-2]-height[i])
                
                );
        }
        
        return dp[n-1];
        
    }
};