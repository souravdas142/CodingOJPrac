#define vvi vector<vector<int> >
#define vi vector<int>
#define svi set<vector<int> >

class Solution {
public:
    void solve(vi& nums,int n, int index, vvi& ans,svi& res) {
        if(index>=n) {
            res.insert(nums);
            return;
        }

        for(int i = index;i<n;i++) {
            if(i>index && nums[i]==nums[i-1]) continue;
            swap(nums[i],nums[index]);
            
            
            solve(nums,n,index+1,ans,res);
            swap(nums[i],nums[index]);
            
            

        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int index = 0;

        vvi ans;
        svi res;

        solve(nums,n,index,ans,res);

        ans = vvi(res.begin(),res.end());

        return ans;

    }
};