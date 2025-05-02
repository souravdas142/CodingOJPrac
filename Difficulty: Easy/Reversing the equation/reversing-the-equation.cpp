//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    string reverseEqn(string s) {
        // code here.
        // 20-3+5*2
        // 2*5+3-20
        
        int sz = s.size();
        string ans = "",dummy="";
        for(int i = 0;i<sz;i++) {
            if(s[i]>='0' && s[i]<='9') {
                dummy = dummy+s[i];
                //cout<<"dummy = "<<dummy<<endl;
            }
            else {
                ans = s[i]+dummy+ans;
                //cout<<ans<<endl;
                dummy="";
            }
        }
        ans = dummy+ans;
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    
cout << "~" << "\n";
}
}
// Contributed By: Pranay Bansal

// } Driver Code Ends