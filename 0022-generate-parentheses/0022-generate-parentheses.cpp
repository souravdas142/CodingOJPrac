class Solution {
public:

    void solve(string& brackets,unordered_map<string,bool>& check, int n,int opn, int cls,vector<string>& ans, string res) {

        cout<<res<<endl;

        if(res.size()>=n*2) {
           
                ans.push_back(res);
            return;
        }

        if(cls>opn) return;

        if(opn<n && check.find(res+brackets[0])==check.end()) {
            res.push_back(brackets[0]);
            
                opn++;
                check[res] = true;
                solve(brackets,check,n,opn,cls,ans,res);
                opn--;
            
            res.pop_back();
            //cout<<"opn "<<res<<endl;
        } 
        if(cls<n && check.find(res+brackets[1])==check.end()) {
            
            res+=brackets[1];
            
                cls++;
                check[res] = true;
                
                solve(brackets,check,n,opn,cls,ans,res);
                cls--;
            
            res.pop_back();
            //cout<<res<<endl;

        }
        

    }
    vector<string> generateParenthesis(int n) {

        string brackets = "()";

        vector<string> ans;
        string res = "";
        int opn = 0, cls = 0;
        unordered_map<string,bool> check;
        solve(brackets,check,n,opn, cls, ans,res);

        return ans;
        
    }
};