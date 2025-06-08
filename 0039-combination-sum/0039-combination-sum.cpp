#define vvi vector<vector<int> >
#define vi vector<int> 

class Solution {
public:

    void solve1(vi& candidates, int n, int index, vvi& ans, vi res, int target) {
        if(index>=n || target <= 0) {
            if(target==0) {
                ans.push_back(res);
            }
            return;
        }
        //take
        res.push_back(candidates[index]);
            
        solve1(candidates,n,index,ans, res,target-candidates[index]);
        res.pop_back();
        
        solve1(candidates,n,index+1,ans,res,target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        int n = candidates.size();
        int index = 0;

        vvi ans;
        vi res;

        solve1(candidates,n,index,ans,res,target);

        return ans;

        
    }
};