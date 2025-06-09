class Solution {
    void solve(vector<int>& nums,int sz,int index,vector<int> res, vector<vector<int> >& ans,map<vector<int>,bool>& mp) {
        if(index>=sz) {
            if(!mp.count(res)) {
                ans.push_back(res);
                mp[res] = true;
            }
            
            return;

        }
        for(int i = index;i<sz;i++) {
            if(i>index && nums[i]==nums[i-1]) continue;
            solve(nums,sz,i+1,res,ans,mp);
            res.push_back(nums[i]);
            solve(nums,sz,i+1,res,ans,mp);
            res.pop_back();
            
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int sz = nums.size();
        map<vector<int>,bool > mp;
        int index = 0;
        vector<vector<int> > ans;
        vector<int> result;
        solve(nums,sz,index,result,ans,mp);
        return ans;
        
    }
};