//{ Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(vector<int>& arr) {
        // Your code here
        
        bool is_sorted = false;
        int sz = arr.size();
        for(int i = 0;i<sz;i++) {
            is_sorted = false;
            for(int j = 1;j<sz-i;j++) {
                if(arr[j]<arr[j-1]) {
                    swap(arr[j-1],arr[j]);
                    is_sorted=true;
                }
               
            }
             if(is_sorted==false) return;
        }
    }
};



//{ Driver Code Starts.

// Driver program to test above functions
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

        ob.bubbleSort(arr);
        for (int e : arr) {
            cout << e << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends