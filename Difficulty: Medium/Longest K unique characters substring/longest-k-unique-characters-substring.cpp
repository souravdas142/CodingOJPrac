//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int n = s.length();
        int ans = 0;
        unordered_map<char,int> ump;
        int i = 0, j = 0;
        while(j<n) {
            ump[s[j]]++;
            if(ump.size()>k) {
                ump[s[i]]--;
                if(ump[s[i]]==0) {
                    ump.erase(s[i]);
                }
                i++;
                
            }
            if(ump.size()==k) {
                ans = max(ans,j-i+1);
            }
            j++;
        }
        if(ans==0) return -1;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends