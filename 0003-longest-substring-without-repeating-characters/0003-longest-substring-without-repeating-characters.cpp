


class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        if(n==0) return 0;
        int maxi = 1;
        int i = 0;
        int j = 0;
        unordered_map<char,int> look;

        while(j<n) {
          if(look[s[j]]!=-1) {
            i = max(i,look[s[j]]+1);
          }
          look[s[j]]=j;
          maxi = max(maxi,j-i+1);
          j++;
        }
        return maxi;
    }
};