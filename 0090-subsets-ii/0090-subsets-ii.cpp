#define vvi vector<vector<int> >
#define vi vector<int>
#define svi set<vector<int> >

class Solution {
public:

    void solve(vi& nums, int n, int index, vvi& ans, vi res) {
        if(index>=n) {
            ans.push_back(res);
            return;
        }

        for(int i = index;i<n;i++) {

            if(i>index && nums[i]==nums[i-1]) continue;

            res.push_back(nums[i]);
            solve(nums,n,index+1,ans,res);
            res.pop_back();
            solve(nums,n,index+1,ans,res);
            
        }
    }

    void solve2(vi& nums, int n, int index, svi& sans, vi res) {
        if(index>=n) {
            sans.insert(res);
            return;
        }
        res.push_back(nums[index]);
        solve2(nums,n,index+1,sans,res);
        res.pop_back();
        solve2(nums,n,index+1,sans,res);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        int n = nums.size();
        //sort(nums.begin(),nums.end());
        int index = 0;
        vvi ans;
        vi res;

        svi sans;

        solve2(nums,n,index, sans, res);

        ans = vvi(sans.begin(),sans.end());

        return ans;

        
    }
};