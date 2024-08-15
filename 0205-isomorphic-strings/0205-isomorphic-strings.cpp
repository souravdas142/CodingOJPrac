class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,set<char> > ump,ump2;
        int slen = s.length(), tlen = t.length();
        if(slen!=tlen) return false;

        for(int i = 0;i<slen;i++) {
            ump[s[i]].insert(t[i]);
            ump2[t[i]].insert(s[i]);
            /// not sure??
        }

        for(pair<char,set<char> > s:ump) {
            if(s.second.size()>1) return false;
        }
        for(pair<char,set<char> > s:ump2) {
            if(s.second.size()>1) return false;
        }

        return true;

        
    }
};