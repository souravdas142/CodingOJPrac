//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        
        
        int arr1sz = arr1.size();
        int arr2sz = arr2.size();
        int i = 0, j = 0,cnt = 0;
        int ele = -1;
        
        while(i<arr1sz && j<arr2sz) {
            if(arr1[i]<arr2[j]) {
                ele = arr1[i];
                i++;
            }
            else if(arr1[i]>arr2[j]) {
                ele = arr2[j];
                j++;
            }
            else if(arr1[i]==arr2[j]) {
                ele = arr1[i];
                j++;i++;
                k--;
            }
            k--;
            if(k<=0) {
                break;
            }
            
        }
        
        
        if(k>0 && i<arr1sz) {
            ele = arr1[i+k-1];
        }
        else if(k>0 && j<arr2sz) {
            ele = arr2[j+k-1];
        }
        
        return ele;
        
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends