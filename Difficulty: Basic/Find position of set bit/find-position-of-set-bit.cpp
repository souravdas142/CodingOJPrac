class Solution {
  public:
    int findPosition(int n) {
        // code here
        if(n==0) return -1;
        int check = (n&(n-1));
        if(check) return -1;
        if(n==1) return 1;
        return log2(n)+1;
    }
};