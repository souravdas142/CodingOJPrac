class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int n = s.length();
        int i = 0;
        int j = 0;
        int cnt = 0;
        unordered_map<char,int> ump;
        while(j<n) {
            ump[s[j]] = j;
            if(ump.size()==3) {
                int mn = min(ump['a'],min(ump['b'],ump['c']));
                cnt+= (mn-i)+1;
            }
            j++;
        }
        return cnt;
    }
};