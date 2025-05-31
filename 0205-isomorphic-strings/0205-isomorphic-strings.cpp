class Solution {
public:
    bool isIsomorphic(string s, string t) {

        unordered_map<char,char> ump1, ump2;
        int n = s.length(), m = t.length();
        if(n!=m) return false;

        for(int i = 0;i<n;i++) {

            if(ump1.find(s[i])==ump1.end()) {
                ump1[s[i]] = t[i];
            }
            else {
                if(ump1[s[i]]!=t[i]) return false;
            }
            if(ump2.find(t[i])==ump2.end()) {
                ump2[t[i]] = s[i];
            }
            else {
                if(ump2[t[i]]!=s[i])
                    return false;
            }
        }

        
        return true;
        
    }
};