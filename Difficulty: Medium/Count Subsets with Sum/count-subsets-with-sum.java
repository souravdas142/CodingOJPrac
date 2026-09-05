class Solution {
    
    public static int solve(int[] arr, int index, int target) {
      
        
      if (index == 0) {
              if (target == arr[0] && arr[0] == 0) return 2; // pick or don't pick
              if (target == 0 || arr[0] == target) return 1; // 1 way
              return 0; // impossible
          }
        
        
        int notTake = solve(arr,index-1,target);
        
        int take = 0;
        if(target>=arr[index])
            take = solve(arr,index-1,target-arr[index]);
        
        return take+notTake;
    }
    
    public static int solve1(int[] arr, int k) {
        int n = arr.length;
        
        int[][] dp = new int[n][k+1];
      
        // for(int i = 0;i<n;i++) {
        //     dp[i][0] = 1;
            
        // }
        
        // // if(arr[0]<=k) dp[0][arr[0]] = 1;
        // // if(arr[0]<=k && arr[0]==0) dp[0][arr[0]] = 2;
        
        // //dp[0][0]=1;
        // if (arr[0] == 0) dp[0][0] = 2; 
        // if (arr[0] <= k) dp[0][arr[0]] = 1; 
          
      
        if (arr[0] == 0) {
            dp[0][0] = 2; // target == 0 and arr[0] == 0 -> 2 ways
        } else {
            dp[0][0] = 1; // target == 0 and arr[0] != 0 -> 1 way (empty set)
            if (arr[0] <= k) {
                dp[0][arr[0]] = 1; // target == arr[0] -> 1 way
            }
        }
        
        for(int index = 1;index<n;index++) {
            for(int target= 0;target<=k;target++) {
                int notTake = dp[index-1][target];
        
                int take = 0;
                if(target>=arr[index])
                    take = dp[index-1][target-arr[index]];
                
                dp[index][target] = take+notTake;
            }
        }
        
        return dp[n-1][k];
        
    }
    
    
    public static int solve2(int[] arr, int k) {
        int n = arr.length;
        
        int[] dp = new int[k+1];
        int[] temp = new int[k+1];
      
        // for(int i = 0;i<n;i++) {
        //     dp[i][0] = 1;
            
        // }
        
        // // if(arr[0]<=k) dp[0][arr[0]] = 1;
        // // if(arr[0]<=k && arr[0]==0) dp[0][arr[0]] = 2;
        
        // //dp[0][0]=1;
        // if (arr[0] == 0) dp[0][0] = 2; 
        // if (arr[0] <= k) dp[0][arr[0]] = 1; 
          
      
        if (arr[0] == 0) {
            dp[0] = 2; // target == 0 and arr[0] == 0 -> 2 ways
        } else {
            dp[0] = 1; // target == 0 and arr[0] != 0 -> 1 way (empty set)
            if (arr[0] <= k) {
                dp[arr[0]] = 1; // target == arr[0] -> 1 way
            }
        }
        
        for(int index = 1;index<n;index++) {
            for(int target= 0;target<=k;target++) {
                int notTake = dp[target];
        
                int take = 0;
                if(target>=arr[index])
                    take = dp[target-arr[index]];
                
                temp[target] = take+notTake;
            }
            int[] swap = dp;
            dp = temp;
            temp = swap;
            
        }
        
        return dp[k];
        
    }
    
    static int perfectSum(int[] arr, int target) {
        // code here
        int n = arr.length;
        int index = n-1;
        int ans = solve2(arr,target);
        return ans;
    }
}