#define vvi vector<vector<int> >
#define vi vector<int> 

class Solution {
public:
    void solve(int index, int n, int k,vi res,vvi& ans, int sum,int target) {
        if(res.size()==k && sum==target) {
            ans.push_back(res);
            return;
        }
        for(int i = index;i<=n;i++) {
            sum+=i;
            res.push_back(i);
            solve(i+1,n,k,res,ans,sum,target);
            if(sum==target) {
                
                break;
            }
            sum-=i;
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int index = 1;
        int target = n;
        int sum = 0;
        vector<int> res;
        vvi ans;
        n = 9;
        solve(index,n,k,res,ans,sum,target);
        return ans;
        
    }
};