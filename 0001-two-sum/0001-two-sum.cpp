class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> ans;

        int sz = nums.size();
        for(int i = 0;i<sz;i++) {
            for(int j = i+1;j<sz;j++) {
                if(nums[i]+nums[j]==target) {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }

        return ans;
        
    }
};