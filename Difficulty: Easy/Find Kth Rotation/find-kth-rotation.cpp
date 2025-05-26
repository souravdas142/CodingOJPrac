// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int mid = 0;
        while(low<high) {
            mid = low+((high-low)>>1);
            
            if(arr[mid]>=arr[low] && arr[mid]>=arr[high]) {
                low = mid+1;
            }
            else {
                high = mid;
            }
        }
        return high;
    }
};
