class Solution {
  public:
    int countMinReversals(string s) {
            // code here
        int n = s.length();
        if (n % 2 != 0) return -1;
    
        stack<char> st;
        for (char c : s) {
            if (!st.empty() && st.top() == '{' && c == '}') {
                st.pop();
            } else {
                st.push(c);
            }
        }

          
        int open = 0, close = 0;
        while (!st.empty()) {
            if (st.top() == '{') open++;
            else close++;
            st.pop();
        }
    
        return (open + 1) / 2 + (close + 1) / 2;
    }
};