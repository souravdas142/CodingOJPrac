class Solution {
public:
    string largestOddNumber(string num) {

        int n = num.size();
        int i = n-1;
        while(i>=0) {
            if((num[i]-'0')&1) {
                return string(num.begin(),num.begin()+i+1);
            }
            i--;
        }

        return "";
        
    }
};