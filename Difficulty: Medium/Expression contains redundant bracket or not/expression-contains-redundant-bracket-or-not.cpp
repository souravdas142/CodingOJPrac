class Solution {
  public:
    bool checkRedundancy(string &s) {
        // code here
        int n = s.size();
        int j = 0;
        stack<char> st;
        
        while(j<n) {
            
            if(s[j]==')') {
                int cnt = 0;
                while(st.top()!='(') {
                    st.pop();
                    cnt++;
                }
                st.pop();
                if(cnt<=1) return true;
                
                
            }
            
            st.push(s[j]);
            
            
            j++;
        }
        
        return false;
    }
};
