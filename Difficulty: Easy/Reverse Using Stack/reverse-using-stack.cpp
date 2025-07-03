class Solution {
  public:
    string reverse(const string& s) {
        // code here
        stack<char> st;
        string ans = "";
        for(const char& ch: s) {
            st.push(ch);
        }
        while(!st.empty()) {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};