//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        
        int n = a.size();
        int m = b.size();
        
        unordered_map<int,int> look;
        
        
        if(n>m)
            for(auto ele:a) look[ele]++;
        else 
            for (auto ele: b) look[ele]++;
            
        
        if(n>m) {
            for(auto ele: b) {
                if(look[ele]<=0) return false;
                else look[ele]--;
            }
            return true;
        }
        
        for(auto ele: a) {
            if(look[ele]<=0) return false;
            else look[ele]--;
        }
        return true;
        
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a1, a2;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a1.push_back(number);
        }
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            a2.push_back(number);
        }
        Solution s;
        bool ans = s.isSubset(a1, a2);
        if (ans) {
            cout << "true"
                 << "\n";
        } else {
            cout << "false"
                 << "\n";
        }
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends