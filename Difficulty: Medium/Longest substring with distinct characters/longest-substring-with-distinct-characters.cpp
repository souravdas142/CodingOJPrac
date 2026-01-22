class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int n = s.size();
        vector<int> check(26,0);
        
        
        int j = 0, i = 0;
        int ans = 0;
        
        while(j<n) {
            check[s[j]-'a']++;
            while(check[s[j]-'a']>1) {
                check[s[i]-'a']--;
                i++;
            }
            
            ans = max(ans,j-i+1);
            j++;
        }
        
        return ans;
    }
};
