//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int i = 0;
        int n = arr.size();
        int dup = 0;
        int missing  = 0;
        
        while(i<n) {
            
            
            if(arr[i]!=arr[arr[i]-1]) {
                swap(arr[i],arr[arr[i]-1]);
            }
            else {
                i++;
            }
            
           
        }
        
        i = 0;
        while(i<n) {
            if(arr[i]!=i+1) {
                missing = i+1;
                dup = arr[i];
            }
            i++;
        }
        
        return {dup,missing};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends