class Solution {
public:
    int reverse(int x) {

        long int cons=0;
        while(x){
            int tmp=x%10;
           
            cons=cons*10+tmp;
            
            if(cons<INT_MIN || cons > INT_MAX) return 0;
            x=x/10;
        }
        return cons;
        
    }
};