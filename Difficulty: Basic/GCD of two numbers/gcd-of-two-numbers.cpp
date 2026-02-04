class Solution {
  public:
    int gcd(int a, int b) {
        // code here
        if(b%a==0) return a;
        
        if(b>a) return gcd(a,b%a);
        return gcd(b%a,a);
    }
};
