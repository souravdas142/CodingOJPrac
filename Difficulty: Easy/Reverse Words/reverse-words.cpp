//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
  void reverse_(string& s,int i,int j) {
      while(i<=j) {
          swap(s[i],s[j]);
          i++;j--;
      }
  }
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        int i = 0,j = 0;
        int n = str.length();
        while(j<n) {
            if(str[j]=='.') {
                
                
                reverse_(str,i,j-1);
                
                i=j+1;
                
                
                
            }
            j++;
        }
        reverse_(str,i,j-1);
        
        reverse_(str,0,n-1);
        return str;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends