class Solution {
public:
    int addDigits(int num) {
        
       if(num<10) return num;
        //if(sz==1) return num;

        int x = 0;

        while(num) {
            x+=num%10;
            num/=10;
        }



        return addDigits(x);
        
    }
};