// User function template for C++

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // your code here
        
        int n = s.size();
        int i = 0;
        int j = 0;
        unordered_map<char,int> ump;
        int ans = -1;
        
        while(j<n) {
            ump[s[j]]++;
            
            if(ump.size()>k) {
                ump[s[i]]--;
                if(ump[s[i]]==0) ump.erase(s[i]);
                i++;
            }
            if(ump.size()==k) {
                ans = max(ans,j-i+1);
            }
            j++;
        }
        
        return ans;
        
    }
};