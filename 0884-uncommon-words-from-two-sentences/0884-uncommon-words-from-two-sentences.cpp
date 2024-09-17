class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {

        unordered_map<string,int> st,st2;
        vector<string> ans;
        int len = s1.length();
        string dum;
        for(int i = 0;i<len;i++) {
            if(s1[i]==' ') {
                st[dum]++;
                dum = "";
            }
            else {
                dum+=s1[i];
            }
        }
        st[dum]++;
        dum = "";
        len = s2.length();
        for(int i = 0;i<len;i++) {
            if(s2[i]==' ') {
                st2[dum]++;
                dum="";
            }
            else {
                dum+=s2[i];
            }
        }
        
        st2[dum]++;

        for(auto it:st) {
            if(st2.count(it.first)==0 && st[it.first]==1) {
                ans.push_back(it.first);
            }
        }

        for(auto it:st2) {
            if(st.count(it.first)==0 && st2[it.first]==1) {
                ans.push_back(it.first);
            }
        }

        return ans;
        
    }
};