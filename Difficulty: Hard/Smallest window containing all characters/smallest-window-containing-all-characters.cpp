class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        // code here
        unordered_map<char,int> ump;
        for(auto& ch: p) ump[ch]++;
        
        
        int ns = s.size();
        int np = p.size();
        int len = INT_MAX;
        
        int i = 0, j = 0;
        int cnt = 0;
        int startingIndex = 0;
        
        while(j<ns) {
            
            ump[s[j]]--;
            
            if(ump[s[j]]>=0) cnt++;
            
            while(cnt==np) {
                
                if(j-i+1<len) {
                    startingIndex = i;
                    len = j-i+1;
                }
                
                
                ump[s[i]]++;
                if(ump[s[i]]>=1) {
                    cnt--;
                }
                i++;
            }
            
            j++;
            
            
        }
        
        if(len == INT_MAX) len = 0;
        
        string strans = s.substr(startingIndex,len);
        return strans;
        
    }
};