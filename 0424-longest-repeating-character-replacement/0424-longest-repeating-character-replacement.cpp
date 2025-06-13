class Solution {
public:
    int characterReplacement(string s, int k) {

        int n = s.size();
        int i = 0;
        int j = 0;
        
        int maxfreq = 0;
        unordered_map<char,int> freq;
        int mxfreq = 0;

        while(j<n) {
            freq[s[j]]++;

            mxfreq = max(mxfreq,freq[s[j]]);
            int need_changes = j-i+1-mxfreq;

          if(need_changes>k) {
            freq[s[i]]--;
            if(freq[s[i]]==0) freq.erase(s[i]);
            i++;
          }   
          if(need_changes<=k) {
                maxfreq = max(maxfreq,j-i+1);
          } 

          

            
          j++;
            
            
           
        }

        return maxfreq;
        
    }
};