class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        int j = 0;
        int i = 0;
        int sum = 0;
        unordered_map<int,bool> ump;
        int target = 0;
       
        while(j<n) {
            sum+=arr[j];
            if(sum == 0 ) return true;
            
            int need = sum-target;
            if(ump.find(need)!=ump.end()) {
                return true;
            }
            
            ump[sum] = true;
            j++;
            
        }
        
        return false;
    }
};