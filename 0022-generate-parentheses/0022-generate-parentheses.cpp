class Solution {
    void solve(int depth,int left, int right,string res,vector<string>& ans) {

        

        if(left==depth && left==right) {
            
                ans.push_back(res);
                
            
            return;
        }

        if(left>depth || right>depth) return;


        
        /// take
        if(left<depth) {
            res.push_back('(');
            solve(depth,left+1,right,res,ans);
            res.pop_back();
        }
    

        if(left>right && right<depth) {
            res.push_back(')');
            
            solve(depth,left,right+1,res,ans);
            res.pop_back();
        }
        

    }
public:
    vector<string> generateParenthesis(int n) {

        int depth = n;

        string res;
        vector<string> ans;

        int left = 0, right = 0;

        solve(depth,left,right,res,ans);

        return ans;
        
    }
};