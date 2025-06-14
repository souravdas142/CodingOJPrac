#define debug(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl;
class Solution {
public:
    bool isValid(string s) {

        int n = s.size();
        stack<char> st;
        int j = 0;
        while(j<n) {
        //debug(s[j],(int)s[j]);

            if(s[j] == '(' || s[j] == '{' || s[j] == '[') {
                
                st.push(s[j]);
            }
            else {
                if((st.top() == '(' && s[j] == ')') || (st.top() == '{' && s[j] == '}') || (st.top() == '[' && s[j] == ']') ) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
            j++;
        }
        return st.empty();
    }
};