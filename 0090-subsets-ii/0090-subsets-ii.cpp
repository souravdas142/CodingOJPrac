#define vvi vector<vector<int> >
#define vi vector<int>
#define svi set<vector<int> >

class Solution {
public:
    void solve(vi& nums,int sz,int index,vi res,svi& ans) {

        if(index>=sz) {

            ans.insert(res);

            return;
        }

        solve(nums,sz,index+1,res,ans);

        int ele = nums[index];
        res.push_back(ele);
        sort(res.begin(),res.end());
        solve(nums,sz,index+1,res,ans);



    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        svi svans;
        vvi ans;
        vi res;
        int sz = nums.size();
        int index = 0;
        solve(nums,sz,index,res,svans);
        for(auto ele:svans) ans.push_back(ele);
        return ans;
        
    }
};