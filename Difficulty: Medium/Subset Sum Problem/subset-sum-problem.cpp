#define vi vector<int>
#define vvi vector<vi>

class Solution {
  public:
    bool recurSolve(vector<int>& arr, int& n, int index, int target,vvi& dp) {
        if(target==0) return true;
        if(index>=n) return false;
        if(dp[index][target]!=-1) return dp[index][target];
        bool not_take = recurSolve(arr,n,index+1,target,dp);
        if(not_take) return true;
        bool take = false;
        if(arr[index]<=target) {
            take = recurSolve(arr,n,index+1,target-arr[index],dp);
            if(take==true) return true;
        }
            
        return dp[index][target] = not_take || take;
        
        
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vvi dp(n,vi(sum+1,-1));
        return recurSolve(arr,n,0,sum,dp);
    }
};