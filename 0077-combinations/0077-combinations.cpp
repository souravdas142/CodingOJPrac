#define vvi vector<vector<int> >
#define vi vector<int>

class Solution {
public:
    void solve(vi& nums,int n, int index,vvi& ans, vi res, int k) {

        if(res.size()>=k) {
            ans.push_back(res);
            return;
        }
        for(int i = index;i<n;i++) {
            
            res.push_back(nums[i]);
            solve(nums,n,i+1,ans,res,k);
            res.pop_back();


        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums(n,0);
        for(int i = 0;i<n;i++) nums[i] = i+1;

        int index = 0;
        vvi ans;
        vi res;
        solve(nums,n,index,ans,res,k);
        return ans;
        
    }
};