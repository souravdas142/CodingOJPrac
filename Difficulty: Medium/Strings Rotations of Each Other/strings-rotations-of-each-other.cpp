class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        int i = 0;
        int j = m-1;
        
        if(n!=m) return false;
        
        s2+=s2;
        
        if(s2.find(s1)!=string::npos) return true;
        
        return false;
        
    }
};