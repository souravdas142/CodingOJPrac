
#define ll long long

class Solution {
public:

    double mypow(double a, ll n) {
        if(n==0) return 1;

        double ans = 1.0f;

        //if(n%2==0)
          ans = mypow(a,n/2);
        

        ans  = ans*ans;

        if(n&1) ans *= a;
               

         return ans;
    }

    double myPow(double a, int n) {
        
        double ans = mypow(a,abs((ll)n));

        if(n<0) ans = (1.0f/ans);

        return ans;


        

    }
};