class Solution {
public:
    bool isAnagram(string s, string t) {
        int sz1 = s.length(),sz2=t.length();
        if(sz1!=sz2) return false;
        unordered_map<char,int> a;
        for(char ch:s) a[ch]++;
        for(char ch:t) a[ch]--;

        for(pair<char,int> pr:a) {
            if(pr.second!=0) return false;
        }
        return true;

        
    }
};