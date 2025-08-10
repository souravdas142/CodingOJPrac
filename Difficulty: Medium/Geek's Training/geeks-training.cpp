
#define vi vector<int> 
#define vvi vector<vi>

class Solution {
  public:
    int recurSolve(vvi& arr, int n,int index,int prevPicked,vvi& dp) {
        if(index<0) {
            return 0;
        }
        if(dp[index][prevPicked]!=-1) return dp[index][prevPicked];
        int maxi = INT_MIN;
        for(int i =0;i<3;i++) {
            if(i!=prevPicked) {
                maxi = max(maxi,recurSolve(arr,n,index-1,i,dp)+arr[index][i]);
            }
        }
        return dp[index][prevPicked] = maxi;
        
    }
    int recurSol(vector<vector<int>>& arr) {
        int n = arr.size();
        int index = n-1;
        int prevPicked = 3;
       vvi dp(n,vi(4,-1)); 
        return recurSolve(arr,n,index,prevPicked,dp);
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        return recurSol(arr);
    }
};