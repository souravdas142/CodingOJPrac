//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  int calcGcd(int a, int b) {
      
      
      if(a==b) return a;
      
      if(a>b) {
          return calcGcd(a-b,b);
      }
      else {
          return calcGcd(a,b-a);
      }
      
      
  }
  
    vector<int> lcmAndGcd(int a, int b) {
        // code here
        vector<int> ans(2,0);
        ans[1] = calcGcd(a,b);
        ans[0] = (a*b)/ans[1];
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int A, B;

        cin >> A >> B;

        Solution ob;
        vector<int> ans = ob.lcmAndGcd(A, B);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends