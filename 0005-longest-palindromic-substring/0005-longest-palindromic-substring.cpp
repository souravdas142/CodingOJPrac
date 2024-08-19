class Solution {

    int expand(string s,int len, int left,int right,string& pans) {

        int ans = 0;
        
        while(right<len && left>=0) {
            if(s[left]!=s[right]) break;
            right++;left--;
        }
        ans =  (right-left-1);
        pans = string(s.begin()+left+1,s.begin()+right);
        return ans;
    }
public:
    string longestPalindrome(string s) {

        int len = s.length();
        if(len==1) return s;
        int i = 0;
        int maxlen = 1;
        string ans;

        while(i<len) {
            // odd
            string oans,eans;
            int odd = expand(s,len,i,i,oans);
            int even = expand(s,len,i,i+1,eans);

            int flen = max(odd,even);

            if(flen>maxlen) {
                maxlen = flen;
                ans = (flen&1)?oans:eans;
                
            }

            i++;
        }


        return ans;
        
    }
};