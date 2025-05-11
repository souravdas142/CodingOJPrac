class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> ump;
        int n = nums.size();
        int need = 0;
        for(int i = 0;i<n;i++) {
            need = target - nums[i];
            if(ump.find(need)!=ump.end()) {
                ans.push_back(i);
                ans.push_back(ump[need]);
                break;
            }
            
            ump.insert({nums[i],i});
            
        }

        return ans;
    }
};