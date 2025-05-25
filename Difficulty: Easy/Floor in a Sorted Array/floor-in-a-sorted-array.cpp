class Solution {
  public:

    int findFloor(vector<int>& arr, int x) {
        // Your code here
        int n = arr.size();
        int low = 0, high = n-1;
        while(low<high) {
            int mid = low+(high-low)/2;
            if(arr[mid]>x) {
                high = mid;
            }
            else {
                low = mid+1;
            }
        }
        
        if(high == 0 && x<arr[high]) return -1;
        if(arr[high]<x) return high;
        if(arr[high]==x) return high;
        return high-1;
    }
};
