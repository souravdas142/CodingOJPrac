class Solution {
  public:
    vector<int> dirx = {0,1};
    vector<int> diry = {1,0};
    int findPath(int m, int n, int sri, int sci,vector<vector<int>>& dp) {
        if(sri==n-1 && sci == m-1) {
            return 1;
        }
        
        int ans = 0;
        if(dp[sri][sci]!=-1) return dp[sri][sci];
        for(int i = 0;i<2;i++) {
            int newx = sri+dirx[i];
            int newy = sci+diry[i];
            if(newx>=0 && newx<n && newy>=0 && newy<m) {
                ans += findPath(m,n,newx,newy,dp);
            }
        }
        
        return dp[sri][sci] = ans;
        
    }
    int numberOfPaths(int m, int n) {
        // Code Here
        int sri = 0, sci = 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return findPath(m,n,sri,sci,dp);
    }
};
