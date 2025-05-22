class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char,int> ump; // char, index
        int n = s.length();
        if(n==0) return 0;
        int i= 0 ,j = 0;
        int ans = 1;
        while(j<n) {
            if(ump.count(s[j])==1) {
               
                if(ump[s[j]]>=i) {
                    i = ump[s[j]]+1;
                  
                } 
                
            }
            ans = max(ans,j-i+1);
            ump[s[j]] = j;
            j++;
        }
        return ans;
    }
};