#define vi vector<int>
#define vvi vector<vi>


class Solution {
public:
    void solve(vi& candidates, int index, int n, int target, vi res, vvi& ans) {
        
        if(index>=n || target <=0) {
            if(target==0) {
                ans.push_back(res);
            }
            return;
        }

        for(int i = index;i<n;i++) {
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(target-candidates[index]>=0) {
                res.push_back(candidates[i]);
                solve(candidates, i+1,n,target-candidates[i],res,ans);
                res.pop_back();
            }
        }

        

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        int n = candidates.size();
        int index = 0;

        vvi ans;
        vi res;

        sort(candidates.begin(),candidates.end());

        solve(candidates,index,n,target,res,ans);
        return ans;


        
    }
};