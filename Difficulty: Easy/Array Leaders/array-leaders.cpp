

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        
        int n = arr.size();
        int greater = arr[n-1];
        vector<int> ans;
        ans.push_back(arr[n-1]);
        int i = n-2;
        while(i>=0) {
            if(arr[i]>=greater) {
                ans.push_back(arr[i]);
                greater = arr[i];
            }
            i--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};