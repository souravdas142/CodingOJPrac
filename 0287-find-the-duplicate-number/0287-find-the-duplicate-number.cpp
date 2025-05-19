class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        set<int> numset;
        int n = nums.size();
        int ans = 0;
        for(int i = 0;i<n;i++) {
            if(!numset.insert(nums[i]).second) {
                ans = nums[i];
                break;
            }
        }

        return ans;
        
    }
};