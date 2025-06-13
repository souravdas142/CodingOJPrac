class Solution {
public:
    int countSubarray(vector<int>& nums,int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        unordered_map<int,int> ump;
        int ans = 0;

        while(j<n) {
            ump[nums[j]]++;
            while(ump.size()>k) {
                ump[nums[i]]--;
                if(ump[nums[i]]==0) ump.erase(nums[i]);
                i++;
            }

            ans += (j-i+1);
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        int x = countSubarray(nums,k);
        int y = countSubarray(nums,k-1);
        int ans = x-y;

        return ans;
        
    }
};