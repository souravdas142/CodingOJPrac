// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        
        stack<string> st;
        string s = exp;
        int n = exp.size();
        string ans = "";
        int j = 0;
        while(j<n) {
            if( (s[j]>='a' && s[j]<='z') || (s[j]>='A' && s[j]<='Z') || (s[j]>='0' && s[j]<='9') ) {
                st.push(string(1,s[j]));
            }
            else {
                string a = st.top();
              
                st.pop();
                string b = st.top();
               
                st.pop();
                string tmp = ('('+b+s[j]+a+')');
                st.push(tmp);
            }
            j++;
        }
        return st.top();
        
    }
};