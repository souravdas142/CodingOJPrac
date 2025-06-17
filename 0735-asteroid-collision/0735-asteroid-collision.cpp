class Solution {
    int dir(int a) {
        if(a<0) return -1;
        return 1;
    }
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        int dirj = 1;
        stack<int> st;
        
        for(int j = 0;j<n;j++) {

            int a = ast[j];
            dirj = dir(ast[j]);
            int sz = abs(ast[j]);

            if(st.empty() || (!st.empty() && dirj == dir(st.top()) )) {
                st.push(ast[j]);
                continue;
            }

            while(!st.empty() && dir(st.top()) == 1 && dirj==-1) {
                if(!st.empty() && sz>st.top()) {
                    st.pop();
                }
                else if(!st.empty() && sz == st.top()) {
                    st.pop();
                    sz = 0;
                    break;
                }
                else if(!st.empty() && sz<st.top()) {
                    sz = 0;
                    break;
                }
            }

            if(a<0 && sz>0) {
                st.push(a);

            }
            if(a>=0) {
                st.push(a);
            }




        }

        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};