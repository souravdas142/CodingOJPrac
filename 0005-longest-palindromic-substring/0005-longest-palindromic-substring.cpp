class Solution {
public:
    void checkPalindrome(string& s,int n, int mid1,int mid2,string& ans, int& len) {
        int l = 0;
        while(mid1>=0 && mid2<n) {
            if(s[mid1]==s[mid2]) {
                if(mid2-mid1+1>len) {
                    len = mid2-mid1+l;
                    ans = string(s.begin()+mid1,s.begin()+mid2+1);
                }
            }
            mid1--;
            mid2++;
        }
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        int len = INT_MIN;
        for(int i =0;i<n;i++) {
            checkPalindrome(s,n,i,i,ans,len);
            checkPalindrome(s,n,i,i+1,ans,len);
        }
        return ans;
    }
};