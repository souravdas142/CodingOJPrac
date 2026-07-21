class Solution {
    private int rangeDiff(int x) {
        int maxi = Integer.MIN_VALUE;
        int mini = Integer.MAX_VALUE;

        while(x!=0) {
            int u = x%10;
            maxi = Math.max(u,maxi);
            mini = Math.min(u,mini);
            x = x/10;
        }

        return (maxi-mini);
    }
    public int maxDigitRange(int[] nums) {
        int n = nums.length;

        int[] maxi = new int[n];
        int maxRangeDiff = 0;

        for(int i = 0;i<n;i++) {
            maxi[i] = rangeDiff(nums[i]);
            maxRangeDiff = Math.max(maxRangeDiff,maxi[i]);
        }

        int ans = 0;

        for(int i = 0;i<n;i++) {
            if(maxi[i]==maxRangeDiff) {
                ans+=nums[i];
            }
        }

        return ans;


    }
}