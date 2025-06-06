// User function template for C++

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // your code here
        unordered_map<char,int> ump;
        int i = 0;
        int j = 0;
        int n = s.length();
        int ans = -1;
        while(j<n) {
            ump[s[j]]++;
            
            if(ump.size()>k) {
                ump[s[i]]--;
                if(ump[s[i]]==0)
                    ump.erase(s[i]);
                i++;
            }
            if(ump.size()==k)
                ans = max(ans,j-i+1);
            j++;
        }
        
        return ans;
    }
};