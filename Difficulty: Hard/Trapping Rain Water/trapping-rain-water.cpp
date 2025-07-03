class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        int left = 0, leftmax = arr[0];
        int right = n-1, rightmax = arr[n-1];
        int ans = 0;
        
        while(left<=right) {
            if(leftmax<=rightmax) {
                int mini = min(leftmax,rightmax);
                ans+=max(0,mini-arr[left]);
                if(arr[left]>leftmax) leftmax = arr[left];
                left++;
            }
            else if(rightmax<=leftmax) {
                int mini = min(leftmax,rightmax);
                ans+= max(0,mini-arr[right]);
                if(arr[right]>rightmax) rightmax = arr[right];
                right--;
            }
        }
        
        return ans;
    }
};