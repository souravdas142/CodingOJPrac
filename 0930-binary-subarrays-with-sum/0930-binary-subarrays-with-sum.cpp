class Solution {
private:
    int calc(vector<int>& nums,int goal) {
        if(goal<0) return 0;
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0;
        int cnt = 0;
        
        while(j<n) {
            sum += nums[j];
            while(sum>goal) {
                sum-=nums[i];
                i++;
            }
            if(sum<=goal) {
                cnt+=(j-i+1);
            }

            j++;
        }
        return cnt;

    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return (calc(nums,goal)-calc(nums,goal-1));


    }
};