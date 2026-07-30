class Solution {
    int maxSubarraySum(int[] arr) {
        // Code here
        int n = arr.length;
        
        int j = 0;
        int sum = 0;
        
        int ans = arr[0];
        
        while(j<n) {
            
            sum+=arr[j];
            
            
            
            ans = Math.max(ans,sum);
            
            if(sum<0) sum = 0;
            j++;
        }
        
        return ans;
    }
}
