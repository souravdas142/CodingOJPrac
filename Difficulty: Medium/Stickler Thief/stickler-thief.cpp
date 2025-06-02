class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        // code here
        int pos1 = arr[0];
        int pos2 = 0;
        int i = 1;
        int n = arr.size();
        int ans = 0;
        while(i<n) {
            ans = max(pos2+arr[i],pos1);
            pos2 = pos1;
            pos1 = ans;
            i++;   
        }
        
        return ans;
    }
};