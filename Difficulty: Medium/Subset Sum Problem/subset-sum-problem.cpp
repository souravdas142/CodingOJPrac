class Solution {
  public:
    bool recurSol(vector<int>& arr, int i, int sum) {
        if(sum==0) return true;
        
        if(i<0) return false;
        
        bool x = recurSol(arr,i-1,sum);
        if(x==true) return true;
        
        if(arr[i]<=sum) {
            bool y = recurSol(arr,i-1,sum-arr[i]);
            if(y==true) return true;
        }
        return false;
    }
    
    bool memoSol(vector<int>& arr, int i, int sum,vector<vector<int>>& dp) {
        if(sum==0) return dp[i][sum] = true;
        
        if(i==0) return dp[i][sum] = sum==arr[i];
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        
        bool x = memoSol(arr,i-1,sum,dp);
        if(x==true) return dp[i][sum] = true;
        bool y = false;
        if(arr[i]<=sum) {
            y = memoSol(arr,i-1,sum-arr[i],dp);
            if(y==true) return dp[i][sum] = true;
        }
        return dp[i][sum] = x  || y;
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        // return recurSol(arr,n-1,sum);
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return memoSol(arr,n-1,sum,dp);
    }
};