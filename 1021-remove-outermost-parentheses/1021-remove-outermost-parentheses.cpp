class Solution {
public:
    string removeOuterParentheses(string s) {

        int left =  0;
        int len = s.length();
        int i= 0;
        string intm="",ans;
        while(i<len) {
            if(s[i]=='(') {
                if(left>0)
                    intm.push_back('(');
                left++;
                
            }
            else {
                left--;
                if(left>0)
                    intm.push_back(')');
                if(left == 0) {
                    
                    ans+=intm;
                    intm="";
                }
            }
            i++;
        }
        return ans;
        
    }
};