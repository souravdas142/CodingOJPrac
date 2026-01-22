class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n = arr.size();
        int k = 2;
        
        int i  = 0, j = 0;
        
        unordered_map<int,int> ump;
        
        int ans = 0;
        
        
        while(j<n) {
            
            ump[arr[j]]++;
            
            while(ump.size()>2) {
                ump[arr[i]]--;
                if(ump[arr[i]]==0) ump.erase(arr[i]);
                
                i++;
                
            }
            
            ans = max(ans,j-i+1);
            
            j++;
            
        }
        
        return ans;
    }
};