class Solution {
  public:
    // Function to check if two strings are isomorphic.
    bool areIsomorphic(string &s1, string &s2) {

        // Your code here
        unordered_map<char,char> ump1,ump2;
        
        int n = s1.size();
        int m = s2.size();
        if(n!=m) return false;
        
        for(int i = 0;i<n;i++) {
            if(ump1.find(s1[i]) != ump1.end()) {
                if(ump1[s1[i]]!=s2[i]) return false;
            }
            ump1[s1[i]] = s2[i];
        }    
        
        for(int i = 0;i<m;i++) {
            if(ump2.find(s2[i]) != ump2.end()) {
                if(ump2[s2[i]]!=s1[i]) return false;
            }
            ump2[s2[i]] = s1[i];
        }  
        
        if(ump1.size()!=ump2.size()) return false;
        
        return true;
        
        
    }
};