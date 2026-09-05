class Solution {
    
    public int solve(int[] arr, int n, int target, boolean[][] dp) {
        
        
        for(int i= 0;i<n;i++) dp[i][0] = true;
        
      
       
       dp[0][arr[0]] = true;
        
       
       for(int i = 1;i<n;i++) {
           for(int j = 1;j<=target;j++) {
               
               
                // not take
                boolean notTake = dp[i-1][j];
                
                boolean take = false;
                
                if(j>=arr[i])
                    take = dp[i-1][j-arr[i]];
                    
                dp[i][j] = (take || notTake);
               
               
           }
       }
        
       
       return util(target,dp[n-1]);
        
        
        
    }
    int util(int target,boolean[] dp) {
        int mini =Integer.MAX_VALUE;
        for(int i = 0;i<=target;i++) {
            // System.out.print(dp[i]+", ");
            if(dp[i]==true) {
                int t2 = target-i;
                if(2*i<=target)
                    mini = Math.min(mini,Math.abs(i-t2));
            }
        }
        return mini;
    }

    public int minDifference(int arr[]) {
        // code here
        int n = arr.length;
        int sum = 0;
        for(int i = 0;i<n;i++) sum+= arr[i];
        boolean[][] dp = new boolean[n][sum+1];
        
            
        
        int ans = solve(arr,n,sum,dp);
        return ans;
    }
}
