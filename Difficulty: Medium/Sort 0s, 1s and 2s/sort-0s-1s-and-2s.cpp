class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n = arr.size();
        int z = -1;
        int rf = 0;
        int re = n;
        int two = n;
        
        while(rf<re) {
            if(arr[rf]==0) {
                z++;
                swap(arr[rf],arr[z]);
                if(rf==z) rf++;
            }
            else if(arr[rf]==2) {
                two--;re--;
                swap(arr[rf],arr[two]);
            }
            else {
                rf++;
            }
        }
         
    }
};