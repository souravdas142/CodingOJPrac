class Solution {
public:

    void solve(vector<int>& candidates, int n, int index,int target,vector<int> res, vector<vector<int> >& ans) {

        if(index>=n || target == 0) {
            if(target == 0) {
                ans.push_back(res);
                
            }
            return;
        }
       
     

        if(target-candidates[index]>=0) {
            res.push_back(candidates[index]);
            solve(candidates, n,index,target-candidates[index],res,ans);
            res.pop_back();
        }

        solve(candidates, n, index+1, target,res,ans);

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        int n = candidates.size();
        int index = 0;
        vector<vector<int> > ans;

        vector<int> res;

        solve(candidates,n,index,target,res,ans);

        return ans;
        
    }
};