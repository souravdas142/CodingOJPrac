class Solution {
public:
    void makePalindrome(string& s, int a, int b) {
        int i = a, j = b;
        while(a<b) {
            swap(s[a],s[b]);
            a++;
            b--;
        }
        //string ans(s.begin()+i,s.begin()+b);
        //return ans;

    }
    void trim(string& s) {
        int n = s.length();
        int j = 0;
        int i = n-1;
        while(s[i]==' ') i--;
        if(i<n-1) s.erase(i+1,n-i);
        while(s[j]==' ') s.erase(0,1);
        i = 0;
        j= 0;
        while(j<s.length()) {
            if(s[j]!=' ') {
                i= j+1;
            }
            else {
                i++;
                while(s[i]==' ') s.erase(i,1);
                i=j;
                
            }
            j++;
        }

        
    }
    
    string reverseWords(string s) {
        trim(s);
        int n = s.length();
        int i = 0;
        int j = 0;
        string ans = "";
        while(j<n) {

            if(s[j]==' ') {
                makePalindrome(s,i,j-1);
                
                i = j+1;
            }
            j++;
        }
        makePalindrome(s,i,j-1);
        makePalindrome(s,0,n-1);
        return s;
        
    }
};