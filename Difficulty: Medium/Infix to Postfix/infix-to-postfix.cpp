class Solution {
  public:
    string infixToPostfix(string& s) {
        // code here
        stack<char> st;
        unordered_map<char,int> preced = {{'(',0},{')',7},{'^',5},{'*',4},{'/',4},{'-',2},{'+',2}};
        string ans = "";
        int n = s.size();
        int j = 0;
        while(j<n) {
            if((s[j]>='a' && s[j]<='z') || (s[j]>='A' && s[j]<='Z') || (s[j]>='0' && s[j]<='9')  ) {
                ans.push_back(s[j]);
            }
            else {
                if(st.empty()) {
                    st.push(s[j]);
                }
                else if(s[j] == '(') {
                    st.push(s[j]);
                }
                else if(s[j]==')') {
                    while(st.empty() == false && st.top()!='(') {
                        ans.push_back(st.top());
                        st.pop();
                    }
                    if(st.empty()==false)
                        st.pop();
                }
                else if(preced[s[j]] > preced[st.top()]) {
                    st.push(s[j]);
                }
                else if(preced[s[j]]<=preced[st.top()]) {
                    while(st.empty()== false && preced[st.top()]>=preced[s[j]]) {
                        ans.push_back(st.top());
                        st.pop();
                    }
                    st.push(s[j]);
                }
            }
            j++;
        }
        
        while(st.empty()==false) {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
        
    }
};
