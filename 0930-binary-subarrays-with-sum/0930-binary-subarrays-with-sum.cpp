#define newln "\n"

class Solution {
public:

    int findSubarrays(vector<int>& nums,int goal) {
        int ans = 0;
        int n = nums.size();
        int j = 0;
        int i = 0;
        int sum = 0;
        while(j<n) {
            sum+=nums[j];
            while(i<=j && sum>goal) {
                sum-=nums[i];
                i++;
            }
            ans+=(j-i+1);


            j++;
        }
        //cout<<ans<<newln;
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        //  x = find all the subarray with goal <= goal
        // y = find all the subarray with goal <= goal - 1
        // the answer will be always x-y

        int x = findSubarrays(nums,goal);
        int y = findSubarrays(nums,goal-1);
        int ans = x-y;

        return ans;
        
    }
};