class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        sort(strs.begin(),strs.end());
        string ans = "";
        string a = strs[0];
        string b = strs.back();
        int alen = a.length();
        int blen = b.length();
        int i = 0,j = 0;
        while(i<alen && j<blen) {
            if(a[i]==b[j]) ans+=a[i];
            else break;
            i++;j++;
        }
        return ans;
        
    }
};