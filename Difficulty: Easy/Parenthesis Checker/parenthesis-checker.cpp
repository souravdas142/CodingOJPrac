
class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        int n = s.size();
        stack<char> st;
        int i = 0;
        while(i<n) {
            
            if(s[i] == '{' || s[i] == '[' || s[i] == '(')
                st.push(s[i]);
            else if(!st.empty()) {
                if(s[i] == '}' && st.top()!='{') return false;
                if(s[i] == ']' && st.top()!='[') return false;
                if(s[i] == ')' && st.top()!='(') return false;
                st.pop();
                
            }
            else if(st.empty() && (s[i] == '}' || s[i] == ']' || s[i] == ')')) {
                return false;
            }
            
            
            i++;
        }
        
        if(!st.empty()) return false;
        
        return true;
    }
};