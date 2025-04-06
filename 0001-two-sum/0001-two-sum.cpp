class Solution {
private:
    void solve(vector<int>& nums,int sz,int index,int target,unordered_map<int,int>& ump,vector<int>& ans) {
        if(index>=sz) return;
        int need = target - nums[index];
        if(ump.count(need)) {
            ans.push_back(index);
            ans.push_back(ump[need]);
            return;
        }
        ump[nums[index]] = index;
        solve(nums,sz,index+1,target,ump,ans);

    }
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sz = nums.size();
        int index = 0;
        unordered_map<int,int> ump;
        vector<int> ans;
        solve(nums,sz,index,target,ump,ans);
        return ans;
    }
};