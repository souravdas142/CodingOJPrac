//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        int i = 0;
        int sum = 0;
        int target = 0;
        unordered_map<int,int> look;
        
        while(i<n) {
            sum+=arr[i];
            if(sum==target) {
                return true;
            }
            
            int need = sum - target;
            if(look.find(need)!=look.end()) {
                return true;
            }
            
            if(look.find(sum)==look.end()) {
                look.insert({sum,i});
            }
            
            i++;
            
            
        }
        
        return false;
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

        Solution obj;
        if (obj.subArrayExists(arr))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends