//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        // code here
        int n = arr.size();
        int i = 0;
        vector<int> pos;
        vector<int> neg;
        while(i<n) {
            if(arr[i]<0) {
                neg.push_back(arr[i]);
            }
            else {
                pos.push_back(arr[i]);
            }
            i++;
            
        }
        i = 0;
        int j = 0;
        int k = 0;
        while(i<pos.size() && j<neg.size()) {
            arr[k++] = pos[i++];
            arr[k++]=neg[j++];
            
            
        }
        
        while(j<neg.size()) {
            arr[k++] = neg[j++];
            
        }
        
        while(i<pos.size()) {
            arr[k++] = pos[i++];
        }
        
        
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends