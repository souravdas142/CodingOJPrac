class Solution {
    void solve(int n,string input,int left,int right,string res,vector<string>& ans) {
            if(left == right && left == n) {
                ans.push_back(res);
                return;
            }

        if(left<n) {
            res.push_back(input[0]);
            solve(n,input,left+1,right,res,ans);
            res.pop_back();
        }
        if(left>right && right<n) {
            res.push_back(input[1]);
            solve(n,input,left,right+1,res,ans);
            res.pop_back();
        }


    }
public:
    vector<string> generateParenthesis(int n) {
        string input = "()";
        int left=0,right = 0;
        string res="";
        vector<string> ans;

        solve(n,input,left,right,res,ans);
        return ans;


        
    }
};