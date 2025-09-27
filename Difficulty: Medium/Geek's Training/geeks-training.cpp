
#define vi vector<int>
#define vvi vector<vi>

class Solution {
  public:
    int recurSol(vvi& nums, int days, int task) {
        if(days<0) return 0;
        int maxi = INT_MIN;
        for(int i = 0;i<3;i++) {
            if(i==task) continue;
            int x = nums[days][i]+recurSol(nums,days-1,i);
            maxi = max(maxi,x);
        }
        return maxi;
    }
    
    int memoSol(vvi& nums, int days, int task,vvi& dp) {
        if(days<0) return 0;
        if(dp[days][task]!=-1) return dp[days][task];
        int maxi = INT_MIN;
        for(int i = 0;i<3;i++) {
            if(i==task) continue;
            int x = nums[days][i]+memoSol(nums,days-1,i,dp);
            maxi = max(maxi,x);
        }
        return dp[days][task] = maxi;
    }
    
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int days = arr.size();
        int index = days-1;
        // return recurSol(arr,days-1,3);
        vvi dp(days,vi(4,-1));
        return memoSol(arr,days-1,3,dp);
    }
};