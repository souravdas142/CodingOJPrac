// User function Template for C++

class Solution {
  public:
                    // S    N       M
    int minimumDays(int d, int n, int x) {
        // code here
        if((x*7 > n*6 && d>6) || x > n  ) return -1;
        int total_food = d*x;
        if(total_food%n==0) return total_food/n;
        return total_food/n+1;
    }
};