class Solution {
  public:
    string rearrangeString(string s) {
        // code here
        int n = s.size();
        unordered_map<char,int> freq;
        int i = 0;
        int maxfreq = 0;
        char ch;
        while(i<n) {
            freq[s[i]]++;
            if(freq[s[i]]>maxfreq) {
                maxfreq = freq[s[i]];
                ch = s[i];
            }
            i++;
            
        }
        
        if(maxfreq>(n+1)/2) 
            return "";
            
        int index = 0;
        string ans(n,0);
        
        while(freq[ch]!=0) {
            ans[index] = ch;
            index+=2;
            freq[ch]--;
        }
        ch = 0;
        
        for(ch = 'a'; ch<='z'; ch++) {
            while(freq[ch]>0) {
                index = (index>=n)?1:index;
                ans[index] = ch;
                index+=2;
                freq[ch]--;
            }
        }
        return ans;
    }
};