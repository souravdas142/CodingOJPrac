class Solution {
    public static boolean solve1(int[] arr, int index, int target) {
        
        if(target==0) return true;
        if(index==0) return arr[index]==target;
        
        
        // not take
        boolean not_take = solve1(arr,index-1,target);
        if(not_take==true) return true;
        
        // take
        
        boolean take = false;
        if(target >= arr[index])
            take = solve1(arr,index-1,target-arr[index]);
        
        return (not_take || take);
    }
    
    public static boolean solve2(int[] arr, int index, int target,int[][] dp) {
        
        if(target==0) return true;
        if(index==0) return arr[index]==target;
        
        
        
        if(dp[index][target]!=-1) return dp[index][target]==1;
        // not take
        boolean not_take = solve2(arr,index-1,target,dp);
        if(not_take==true) {
            dp[index][target] = 1;
            return true;
        }
        
        // take
        
        boolean take = false;
        if(target >= arr[index])
            take = solve2(arr,index-1,target-arr[index],dp);
        
        dp[index][target] = ((not_take || take)==true)?1:0;
        return (not_take || take);
    }
    

    
    public static boolean solve3(int arr[], int target) {
        
        int n = arr.length;
        boolean[][] dp = new boolean[n][target+1];
        
        

        for(int i = 0;i<n;i++) {
            dp[i][0] = true;
        }
        
        if(target>=arr[0])
         dp[0][arr[0]] = true;
        
        for(int i = 1;i<n;i++) {
            for(int j = 1;j<=target;j++) {
                
               
                // not take
                boolean not_take = dp[i-1][j];
                
                // take
                
                boolean take = false;
                if(j >= arr[i])
                    take = dp[i-1][j-arr[i]];
                
                dp[i][j] = (not_take || take);
                
                
            }
        }
        
        for(int i = 0;i<n;i++) {
            if(dp[i][target]==true) return true;
        }
        
        return false;
        
    }
    
    
    public static boolean solve4(int arr[], int target) {
        
        int n = arr.length;
        boolean[] dp = new boolean[target+1];

        dp[0] = true;
        
        
        if(target>=arr[0])
            dp[arr[0]] = true;
        
       for(int i = 1;i<n;i++) {
           boolean[] temp = new boolean[target+1];
            for(int j = 1;j<=target;j++) {
                
               
                // not take
                boolean not_take = dp[j];
                
                // take
                
                boolean take = false;
                if(j >= arr[i])
                    take = dp[j-arr[i]];
                
                temp[j] = (not_take || take);
                
                
            }
            for(int k = 0;k<=target;k++) {
                if(temp[k]==true)
                    dp[k] = temp[k];
            }
       }
        
        
       
            if(dp[target]==true) return true;
        
        
        return false;
        
    }
    
    static boolean isSubsetSum(int arr[], int sum) {
        // code here
        int n = arr.length;
        int index = n-1;
        
        // return solve1(arr,index,sum);
        // int[][] dp = new int[n][sum+1];
        // for(int i = 0;i<n;i++) Arrays.fill(dp[i],-1);
        // return solve2(arr,index,sum,dp);
        return solve4(arr,sum);
    }
}