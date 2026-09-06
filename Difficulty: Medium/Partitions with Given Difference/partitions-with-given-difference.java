class Solution {
    
   
    
    public int solve1(int[] arr, int diff) {
        int n = arr.length;
        
        int k = 0;
        for(int a: arr) k+=a;
        
        if (k < diff || (k + diff) % 2 != 0) {
            return 0;
        }
        
        int[][] dp = new int[n][k+1];
        for(int i = 0;i<n;i++) dp[i][0] = 1;
        dp[0][arr[0]] = 1;
        
        
        
        if (arr[0] == 0) {
            dp[0][0] = 2; // Two choices: take arr[0] or don't take it
        } else {
            dp[0][0] = 1; // One choice: empty set
            if (arr[0] <= k) {
                dp[0][arr[0]] = 1;
            }
        }
        
        for(int index = 1;index<n;index++) {
            for(int target = 0;target<=k;target++) {
                
                int notTake = dp[index-1][target];
                
                int take = 0;
                if(target>=arr[index])
                    take = dp[index-1][target-arr[index]];
                    
                dp[index][target] = take+notTake;
            }
        }
        
        return dp[n-1][k];
        
        // int tsum = k/2;
        // int ans = 0;
        
        // for(int i = 0;i<=tsum;i++) {
        //   //  System.out.print(dp[n-1][i]+", ");
        //     int f = i;
        //     int s = k-f;
        //     int cdiff = Math.abs(f-s);
        //     if(cdiff!=diff) continue;
        //     if(dp[n-1][f]!=0 && dp[n-1][s]!=0) {
        //       // System.out.print(" (fs = "+f+", "+s+") ");
        //         if(f==s) {
        //             ans+=dp[n-1][f];
        //         }
        //         else {
        //             ans+=(dp[n-1][f]*dp[n-1][s]);
        //         }
        //     }
        // }
        // //System.out.println();
        // return ans;
    }
    public int countPartitions(int[] arr, int diff) {
        // code here
        // int n = arr.length;
        // int sum = 0;
        // for(int a: arr) sum+=a;
        
        // // int ans = solve(arr,n-1,sum);
        // return solve1(arr,diff);
        // // return solve2(arr,diff);
        
        int n = arr.length;
        int totalSum = 0;
        for (int a : arr) totalSum += a;
        
        // Impossible cases:
        // 1. diff cannot be larger than total sum
        // 2. (totalSum + diff) must be an even number
        if (totalSum < diff || (totalSum + diff) % 2 != 0) {
            return 0;
        }
        
        int target = (totalSum + diff) / 2;
        int MOD = 1_000_000_007;
        
        int[][] dp = new int[n][target + 1];
        
        // Base case for index 0
        if (arr[0] == 0) {
            dp[0][0] = 2; // Two choices: take arr[0] or don't take it
        } else {
            dp[0][0] = 1; // One choice: empty set
            if (arr[0] <= target) {
                dp[0][arr[0]] = 1;
            }
        }
        
        // Fill the 2D DP table
        for (int index = 1; index < n; index++) {
            for (int t = 0; t <= target; t++) {
                int notTake = dp[index - 1][t];
                
                int take = 0;
                if (t >= arr[index]) {
                    take = dp[index - 1][t - arr[index]];
                }
                
                dp[index][t] = (notTake + take);
            }
        }
        
        return dp[n - 1][target];
        
    }
}
