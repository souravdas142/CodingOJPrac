class Solution {
public:
    int characterReplacement(string s, int k) {
       int n = s.length();
       int i = 0,j = 0;
       int ans = 0;
       int maxfreq = 0;
       unordered_map<char,int> ump;

       while(j<n) {
            ump[s[j]]++;
            maxfreq = max(maxfreq,ump[s[j]]);

            
            while((j-i-maxfreq+1)>k) {
                ump[s[i]]--;
                int updfreq = 0;
                for(auto pr:ump) {
                    updfreq = max(updfreq,pr.second);
                }
                maxfreq = updfreq;
                i++;
            }
            int changes = j-i-maxfreq+1;
            if(changes<=k) {
                ans = max(ans,j-i+1);
            }

            j++;
       }

       return ans;
       
    }
};