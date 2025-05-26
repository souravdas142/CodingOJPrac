class Solution {
  public:
    int cupper_bound(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low<high) {
            int mid = low+(high-low)/2;
            if(arr[mid]>target) {
                high = mid;
            }
            else {
                low = mid+1;
            }
        }
        
        if(arr[high]<=target) return n;
        return high;
        
    }
    int clower_bound(vector<int>& arr,int target) {
        int n =arr.size();
        int high = n-1;
        int low = 0;
        while(low<high) {
            int mid = low+(high-low)/2;
            if(arr[mid]>=target) {
                high = mid;
            }
            else {
                low = mid+1;
            }
        }
        
        if(arr[high]<target) return n;
        else if(arr[high]>target) return -1;
        return high;
    }
    vector<int> find(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int xans = cupper_bound(arr,x);
        int yans = clower_bound(arr,x);
        if(xans==n) {
            if(arr[n-1]==x) xans = n-1;
        }
        else
            xans = xans-1;
        
        if(xans!=-1 && arr[xans]!=x) xans = -1;
        
        
        return {yans,xans};
        
    }
};