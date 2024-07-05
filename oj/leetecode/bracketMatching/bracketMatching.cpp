#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define newln "\n";
#define debug(x) cout<<#x<<" = "<<x<<newln;

class Solution {
    public:

        bool isValid(string s) {
            
/*

'(', ')', '{', '}', '[' and ']', 


*/
            
            stack<char> st;
            ll sz = s.size();

            for(int i=0;i<sz ;i++) {
                
                if(s[i] == ')' || s[i]=='}' || s[i] == ']') {

                    if(st.empty()) {
                        return false;
                    }

                }
                
                switch(s[i]) {
                    case '(':
                    case '{':
                    case '[':
                        st.push(s[i]);
                        break;
                    case ')':
                        if(st.top() == '(') {
                            st.pop();
                        }
                        else {
                            return false;
                        }
                        break;
                    case '}':
                        if(st.top() == '{') {
                            st.pop();
                        }
                        else {
                            return false;
                        }
                        break;
                    case ']':
                        if(st.top() == '[') {
                            st.pop();
                        }
                        else {
                            return false;
                        }
                        break;
                }

                        
                    
                
                
            }
            
            //cout<<st.top()<<endl;

            if(st.empty()) {
                return true;
            }
            return false;




            
        } 



};

int main() {

    Solution solve;
    ll tc = 1; 
    cin>>tc;

    while(tc--) {
         string s; cin>>s;
         bool isValid = solve.isValid(s);
         if(isValid) {
            cout<<s<<" is balanced"<<newln;
         }

         else {

            cout<<s<<" is not balanced"<<newln;
            
         }
         
    }
    
    return 0;


    
}