//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int remove_duplicate(vector<int> &arr) {
        // code here
        int i = 1;
        int n = arr.size();
        int j = 1;
        while(i<n) {
            if(arr[i]!=arr[i-1]) {
                arr[j++] = arr[i];
            }
            i++;
        }
        return j;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.remove_duplicate(arr);
        for (int i = 0; i < ans; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends