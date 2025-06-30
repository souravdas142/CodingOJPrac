#define vi vector<int>
#define vvi vector<vi>


class Solution {
public:
    void solve(vi& cand,int n,int index,vi res, set<vi>& ans,int target) {

        if(index>=n || target == 0) {
            if(target == 0) {
                sort(res.begin(),res.end());
                ans.insert(res);
            }
            return;
        }

        for(int i = index;i<n;i++) {
            if(i>index && cand[i]==cand[i-1]) continue;

            if(cand[i]<=target) {
                res.push_back(cand[i]);
                solve(cand,n,i+1,res,ans,target-cand[i]);
                res.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(),cand.end());
        vector<vector<int> > ans;
        vector<int> res;
        int index = 0;
        int n = cand.size();
        set<vector<int> > ust;
        solve(cand,n,index,res,ust,target);
        for(auto& vr: ust) {
            ans.push_back(vr);
        }
        return ans;
    }
};