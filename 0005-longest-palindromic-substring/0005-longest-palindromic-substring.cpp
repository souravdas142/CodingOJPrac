class Solution {
    bool checkPalindrome(string& s,int i, int j) {
        while(i<=j) {
            if(s[i]!=s[j]) {
                return false;
                
            }
            i++;j--;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {

        int len = s.length();
        int maxlen = 0;
        string ans;
        for(int i = 0;i<len;i++) {
            for(int j= i;j<len;j++) {
                if(checkPalindrome(s,i,j)) {
                    if(j-i+1 > maxlen) {
                        maxlen = j-i+1;
                        ans = string(s.begin()+i,s.begin()+j+1);
                    }
                }

            }
        }
        return ans;
        
    }
};