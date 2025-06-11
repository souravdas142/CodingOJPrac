class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        int cnt = 0;
        while(n) {
            n = n&(n-1);
            cnt++;
        }
        return cnt;
    }
};