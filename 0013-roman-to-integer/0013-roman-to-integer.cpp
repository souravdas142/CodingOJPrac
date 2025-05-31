class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char,int> roman = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

        int n = s.length();
        int i = 0;
        int num = 0;

        while(i<n-1) {
            char r = s[i];
            char r1 = s[i+1];
            if(roman[r]>=roman[r1]) {
                num+=roman[r];
            }
            else {
                int k = roman[r1]-roman[r];
                num+=k;
                i++;
            }



            i++;
        }
        char r = s[i-1];
        char r1 = s[i];

        if(roman[r]>=roman[r1]) {
            num+=roman[r1];
        }
        

        return num;

        
        
    }
};