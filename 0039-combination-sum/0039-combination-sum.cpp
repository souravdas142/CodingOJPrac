class Solution {
    void solve(vector<int>& nums,int sz,int target,int index,vector<int> res,vector<vector<int> >& ans) {
        if(target == 0 || index>=sz) {
            if(target == 0) {
                ans.push_back(res);
                
            }
            return;

        }
        
        /// not taking the number
        if(target-nums[index]>=0) {
            res.push_back(nums[index]);
            solve(nums,sz,target-nums[index],index,res,ans);
            res.pop_back();
        }
        /// taking the number
        solve(nums,sz,target,index+1,res,ans);
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sz = candidates.size();
        int index = 0;
        vector<vector<int> > ans;
        vector<int> res;
        
        solve(candidates,sz,target,index,res,ans);
        return ans;
    }
};