class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0;
        int j = 0;
        int n = s.size();
        int maxfreq = 0;
        int ans=0;
        unordered_map<char,int> ump;

        while(j<n) {
            ump[s[j]]++;

            maxfreq = max(maxfreq,ump[s[j]]);
            

            int howMuchNeedChange = (j-i+1)-maxfreq;

            if(howMuchNeedChange<=k) {
                ans = max(ans,j-i+1);
            }
            else {
                ump[s[i]]--;
                if(ump[s[i]]==0) ump.erase(s[i]);
                i++;
            }

            j++;

        }

        return ans;
    }
};