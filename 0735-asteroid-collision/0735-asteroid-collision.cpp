class Solution {
public:
    vector<int> asteroidCollision(vector<int>& aster) {

        int n = aster.size();
        stack<int> st;
        vector<int> ans;

        int i = 0;

        while(i<n) {

            while(!st.empty() && st.top() < abs(aster[i]) && aster[i]<0) {
                st.pop();
            }

            if(st.empty()) {
                if(aster[i] < 0) {
                    ans.push_back(aster[i]);
                    
                }
                else {
                    st.push(aster[i]);
                }
            }
            else if(st.top() == abs(aster[i]) && aster[i] < 0) {
                st.pop();
            }
            else if(aster[i]>=0) {
                st.push(aster[i]);
            }


            i++;
        }

        if(ans.size() == 0 && st.empty()) return ans;

        int sz = ans.size();

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin()+sz,ans.end());
        return ans;
        
    }
};