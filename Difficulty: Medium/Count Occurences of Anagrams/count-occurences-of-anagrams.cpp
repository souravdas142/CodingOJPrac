// User function template for C++
class Solution {
  public:
    int search(string &pat, string &txt) {
        // code here
        int k = pat.size();
        int n = txt.size();
        int i = 0;
        int j = 0;
        unordered_map<char,int> ump;
        unordered_map<char,int> ana_ump;
        for(auto ch:pat) ana_ump[ch]++;
        int cnt = 0;
        
        while(j<n) {
            while(j<k) {
                ump[txt[j]]++;
                j++;
                if(j==k) {
                    int is_ana = 1;
                    for(auto pr:ana_ump) {
                        if(ump[pr.first]-pr.second<0) is_ana = 0;
                    }
                    if(is_ana) cnt++;
                    
                }
                
                if(j==n) return cnt;
                
            }
            
            ump[txt[i]]--;
            i++;
            ump[txt[j]]++;
            int is_ana = 1;
            for(auto pr:ana_ump) {
                if(ump[pr.first]-pr.second<0) is_ana = 0;
            }
            if(is_ana) cnt++;
            j++;
            
        }
        
        return cnt;
        
    }
};