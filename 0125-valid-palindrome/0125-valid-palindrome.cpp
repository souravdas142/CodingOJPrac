#define ll long long

class Solution {
public:

    bool checkPalindrome(const string& s, ll start, ll end) {
        //cout<<start<<","<<end<<endl;
        //if(start>=end) return true;
        if(start<end) {

            if(isalnum(s[start]) && isalnum(s[end])!=0) {
                //cout<<"ok"<<endl;
                if(tolower(s[start])!=tolower(s[end])) {
                    //cout<<start<<","<<end<<endl;
                    //cout<<s[start]<<","<<s[end]<<endl;
                    return false;
                }
                else  {
                    if(checkPalindrome(s,start+1,end-1)==false) return false;
                    else return true;
                }
            }
            else if(isalnum(s[start])==0) {
                if(!checkPalindrome(s,start+1,end)) return false;
                else return true;
            }
            else if(isalnum(s[end])==0) {
                if(!checkPalindrome(s,start,end-1)) return false;
                else return true;
            }

        }
        
        return true;
        
        
    }

    bool isPalindrome(string s) {
        ll start = 0, end = s.length()-1;
        return checkPalindrome(s,start,end);
        
    }
};