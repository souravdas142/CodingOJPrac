// User function Template for C++

class Solution {
  public:
    int inSequence(int a, int b, int c) {
        // code here
        
        if(c==0) return a==b;
        
        return ((b-a)%c==0);
        
    }
};