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
        int celeb = 0;
        int row = mat.size();
        int col = mat[0].size();
        
        for(int i = 0;i<row;i++) {
            for(int j = 0;j<row;j++) {
                if(i==j) continue;
                if(mat[j][i]==1) celeb++;
            }
            if(celeb==row-1) {
                bool check = false;
                for(int k = 0;k<col;k++) {
                    if(mat[i][k]==1) check = true;
                }
                if(check == false) return i;
            }
            celeb = 0;
        }
        return -1;
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