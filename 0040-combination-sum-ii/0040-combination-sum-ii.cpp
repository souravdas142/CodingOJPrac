class Solution {
void solve(vector<int>& cands,int sz, int index,int target,vector<int> res, vector<vector<int> >& ans) {
    if(index>=sz || target<=0) {

        if(target==0) {
            ans.push_back(res);
        }
        return;
    }
    for(int i = index;i<sz;i++) {
        if(i>index && cands[i]==cands[i-1]) continue;
        //if(i>=sz) break;
        res.push_back(cands[i]);
        solve(cands,sz,i+1,target-cands[i],res,ans);
        res.pop_back();
    }
}
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       vector<vector<int> > ans;
       vector<int> res;
       int sz = candidates.size();

       int index = 0;
       sort(candidates.begin(),candidates.end());
       solve(candidates,sz,index,target,res,ans);
       return ans; 
    }
};