class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> freq(257,0);
        int sz = s.length();
        int ans = 0;
        int i = 0, j = 0;
        int curfreq = 0;
        int cnt = 0;
        while(j<sz) {

            freq[s[j]]++;

            curfreq = freq[s[j]];

            if(curfreq>1) {
                cnt = curfreq;
            }

            if(curfreq<2) {
                ans = max(ans,j-i+1);
            }
            else if(curfreq>1) {
                while(cnt!=1 && i<j) {
                    freq[s[i]]--;
                    if(freq[s[i]]==1) cnt = 1;
                    i++;
                }
            }
            j++;
        }

        return ans;
        
    }
};