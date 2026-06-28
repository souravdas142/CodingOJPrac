class Solution {
    public long maxSum(int[] nums, int k, int mul) {
         //Arrays.sort(nums);
        Arrays.sort(nums);
        int n = nums.length;
        int p = 0;
            int q = n-1;
        while(p<=q) {
            int a = nums[p];
            nums[p] = nums[q];
            nums[q] = a;
            p++;
            q--;
        }
        long totalSum = 0;
        
        for(int i = 0;i<n;i++) {
           if(i==k) break;
            if(mul==0) {
                totalSum+=nums[i];
                
            }
            totalSum += (long)(nums[i]*(long)mul);
            if(mul>0)
                mul--;
            
        }
        return totalSum;
    }
}