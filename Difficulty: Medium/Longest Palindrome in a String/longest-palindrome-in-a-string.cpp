class Solution {
  public:
    string letsTryToExpandArroundLetters(string& str, int f, int s) {
        int n = str.size();
        int j = s;
        int i = f;
        string ans = "";
        int cnt = 0;
        while(s<n) {
            
            int expandi =0;
            int expandj = 0;
            i = f;
            j = s;
            while(i>=0 && j<n) {
                if(str[i]==str[j]) {
                    expandi = i;
                    expandj = j;
                }
                else {
                    break;
                }
                
                i--;j++;
                
            }
            
            if(expandj-expandi+1>cnt) {
                cnt = expandj-expandi+1;
                ans = string(str.begin()+expandi,str.begin()+expandj+1);
            }
            
            
            
            
            
            
            f++;s++;
        } 
        
        return ans;
    }
    
    
    string longestPalindrome(string &s) {
        // code here
        
        string ans1 = letsTryToExpandArroundLetters(s,0,0);
        string ans2 = letsTryToExpandArroundLetters(s,0,1);
        
        if(ans1.size()>ans2.size()) return ans1;
        return ans2;

    }
};