//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  void solve(string& s,int sz, int index, set<string>& ans) {
      if(index>=sz) {
         ans.insert(s);
         return;
      }
      
      for(int j = index;j<sz;j++) {
          swap(s[j],s[index]);
          solve(s,sz,index+1,ans);
          swap(s[j],s[index]);
      }
  }
    vector<string> findPermutation(string &s) {
        // Code here there
        int sz = s.length();
        int index = 0;
        set<string> ans;
        
        solve(s,sz,index,ans);
        vector<string> ans2(ans.begin(),ans.end());
        return ans2;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends