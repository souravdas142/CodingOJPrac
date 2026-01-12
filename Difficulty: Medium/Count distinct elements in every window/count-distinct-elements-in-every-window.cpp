class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        
        int n = arr.size();
        int j = 0;
        unordered_map<int,int> ump;
        vector<int> ans;
        
        while(j<n) {
            while(j<k) {
                ump[arr[j]]++;
                j++;
                if(j==k) {
                    ans.push_back(ump.size());
                }
                
            }
            
            if(j==n) break;
            
            ump[arr[j-k]]--;
            if(ump[arr[j-k]]==0) ump.erase(arr[j-k]);
            ump[arr[j]]++;
            
            ans.push_back(ump.size());
            
            
            
            j++;
            
            
        }
        
        
        return ans;
        
    }
};