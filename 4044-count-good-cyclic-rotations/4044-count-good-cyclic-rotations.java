class Solution {
    public int countGoodRotations(int[] nums) {
        int n = nums.length;
        int fh = n/2;
        long totalSum = 0;
        long halfSum = 0;
        for(int i = 0;i<fh;i++) {
            halfSum+=nums[i];
        }
        totalSum = halfSum;
        for(int i = fh;i<n;i++) {
            totalSum+=nums[i];
        }
        long rest = totalSum-halfSum;

        int c = 0;

        int i = 0;
        int j = fh;
        while(i<n) {
            halfSum-=nums[i];
            halfSum+=nums[j];
            rest = totalSum-halfSum;
            if(halfSum>rest) c++;
            i++;
            j++;
            j=(j%n);
        }
        return c;
    }
}