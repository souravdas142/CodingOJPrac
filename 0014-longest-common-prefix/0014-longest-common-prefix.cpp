class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int sz = strs.size();
        if(sz==1) return strs[0];
        int mn = 201;
        string s;
        int pos = -1;
        for(int i= 0;i<sz;i++) {
            int len = strs[i].length();
            if(len<mn) {
                mn = len;
                s = strs[i];
                pos = i;
            }
        }
        if(mn==0) return "";
        unordered_map<string,int> ump;
        string str;
        for(int i = 0;i<mn;i++) {
            str+=s[i];
            ump[str]=i+1;
            
        }

        int minlen = 0;
        string strlen=s;
        for(int i = 0;i<sz;i++) {
            string eachs = strs[i];
            if(i==pos) continue;
            int eachsz = eachs.length();
            string ls;
            for(int j = 0;j<eachsz;j++) {
                ls+=eachs[j];
                if(!ump.count(ls)){
                    ls.pop_back();
                    break;
                }

            }

            int lssz = ls.size();
            if(lssz == 0) return "";
            if(lssz<strlen.size()) {
                strlen=ls;
            }


        }


        return strlen;
    }
};