class Solution {
  public:
    int recurSol(vector<int>& height, int n,vector<int>& dp) {
        
        //dp[1] = dp[0] + abs(height[1]-height[0]);
        
        if(n==0) return 0;
        if(n==1) return abs(height[1]-height[0]);
        
        if(dp[n]!=-1) return dp[n];
        
         return dp[n] = min(
                
                recurSol(height,n-1,dp)+abs(height[n-1]-height[n]),
                recurSol(height,n-2,dp)+abs(height[n-2]-height[n])
                
            
        );
        
       
    }
    
    int minCost(vector<int>& height) {
        // Code here
        
        
        int n = height.size();
        vector<int> dp(n+1,-1);
        return recurSol(height,n-1,dp);
        
    }
};