class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int snowBall = -1;
        int sz = 0;
        
        int n = arr.size();
        
        int j = 0;
        
        while(j<n) {
            if(arr[j]==0) {
                if(snowBall==-1) {
                    snowBall = j;
                    sz = 0;
                }
                else {
                    sz++;
                    snowBall++;
                }
            }
            else {
                if(snowBall>=0){
                    swap(arr[j],arr[snowBall-sz]);
                    snowBall++;
                    
                }
            }
            j++;
        }
    }
};