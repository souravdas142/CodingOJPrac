class Solution {
public:
    bool isValid(string s) {

        stack<char> st;
        int len = s.length();
        for(int i = 0;i<len;i++) {
            if(s[i]=='(' || s[i] == '{' || s[i]=='[') {
                st.push(s[i]);
            }
            else {
                if(st.size()==0) return false;
                if(s[i]==')' && st.top()!='(') {
                    return false;
                }
                else if(s[i]=='}' && st.top()!='{') {
                    return false;
                }
                else if(s[i]==']' && st.top()!='[') {
                    return false;
                }
                st.pop();
            }
        }
        return true;
    }
};