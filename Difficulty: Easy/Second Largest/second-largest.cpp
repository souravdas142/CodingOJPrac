//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

#define inf ((1e8)+1)

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int second = INT_MIN;
        int largest = arr[0];
        for(int i = 0;i<arr.size();i++) {
            if(arr[i]>largest) {
                second = largest;
                largest = arr[i];
            }
            else if(arr[i]>second && arr[i]!=largest) {
                second = arr[i];
            }
        }
        if(second==INT_MIN) return -1;
        return second;
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
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends