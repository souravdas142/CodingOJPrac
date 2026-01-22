class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int n = s.size();
        
        vector<int> check(26,-1);
        
        int i = 0, j = 0;
        
        
        int ans = 0;
        
        while(j<n) {
            
            if(check[s[j]-'a']!=-1) {
                
                i = max(i,check[s[j]-'a']+1);
                
            }
            
            check[s[j]-'a'] = j;
            
            ans = max(ans,j-i+1);
            j++;
            
        }
        
        return ans;
    }
};
