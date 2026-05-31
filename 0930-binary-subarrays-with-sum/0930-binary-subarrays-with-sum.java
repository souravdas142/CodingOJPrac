class Solution {
    public int calcCnt(int[] nums, int goal) {
        int n = nums.length;
        int i = 0;
        int j = 0;
        int cnt = 0;
        int sum = 0;
        while(j<n) {

            sum+=nums[j];
            while(i<n && i<=j && sum>goal) {
                sum-=nums[i];
                i++;
            }

            if(i<n && i<=j && sum<=goal) 
                cnt+=(j-i+1);

            j++;
        }

        

        return cnt;
    }

    public int numSubarraysWithSum(int[] nums, int goal) {
        int ans = 0;
        ans = calcCnt(nums,goal) - calcCnt(nums,goal-1);
        return ans;
    }
}