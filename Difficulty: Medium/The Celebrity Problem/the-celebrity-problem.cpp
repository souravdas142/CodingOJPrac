//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int ans = 0;
        
        int r = mat.size();
        int c = mat[0].size();
        for(int i = 0;i<r;i++) {
            bool flag = false;
            for(int j = 0;j<c;j++) {
                if(mat[i][j]==1) {
                    flag = true;
                }
            }
            if(flag == false) {
                ans = i;
                break;
            }
        }
        
                // possible but still not sure??
                /*  see below test case
                
                    1 1 0 1 1
                    1 1 0 1 1
                    0 0 0 0 0
                    1 1 0 1 1
                    1 1 0 1 1
                
                    so we have to also check all persion know this also
                */
               
                for(int i = 0;i<r;i++) {
                    if(i==ans) continue;
                    if(mat[i][ans]!=1) return -1;
                }
            
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends