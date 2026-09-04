class Solution {
    
    public int solve(int[] arr, int tsum, int index, int sum) {
        if(index<0) {
            return Math.abs(tsum-(2*sum));
        } 
        
        // notTake
        int notTake = solve(arr,tsum,index-1,sum);

        int take = solve(arr,tsum,index-1,sum+arr[index]);

       
        return Math.min(take,notTake);
        
   
    }
    
    public int solve2(int[] arr, int tsum, int index, int sum, int[][] dp) {
        if(index<0) {
            return Math.abs(tsum-(2*sum));
        } 
        
        if(dp[index][sum]!=-1) return dp[index][sum];
        // notTake
        int notTake = solve2(arr,tsum,index-1,sum,dp);

        int take = solve2(arr,tsum,index-1,sum+arr[index],dp);

       
        return dp[index][sum] = Math.min(take,notTake);
        
   
    }
    
    public int minDifference(int arr[]) {
        // code here
        int n = arr.length;
        int sum = 0;
        for(int i = 0;i<n;i++) sum+=arr[i];
        
        int[][] dp = new int[n+1][sum+1];
        
        for(int i = 0;i<=n;i++) {
            Arrays.fill(dp[i],-1);
        }
        
        int ans = 0;
        int index = n-1;
        // int ans1 = solve(arr,sum,index,ans);
        int ans1 = solve2(arr,sum,index,ans,dp);
        return ans1;
    }
}
