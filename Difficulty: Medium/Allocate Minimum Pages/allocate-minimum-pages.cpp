class Solution {
  public:
    bool checkPos(vector<int>& arr,int n, int maxStudent, int minPages) {
        int student = 1;
        int totalPages = 0;
        for(int i= 0;i<n;i++) {
            totalPages+=arr[i];
            if(totalPages>minPages) {
                student++;
                totalPages = arr[i];
            }
            
            if(student>maxStudent) return false;
        }
        return true;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k>n) return -1;
        
        int low = INT_MIN, high = 0;
        int totalBooks = 0;
        
        for(int e: arr) {
            totalBooks += e;
            low = max(low,e);
        }
        high = totalBooks;
        int ans = -1;
        
        while(low<=high) {
            int mid = low+(high-low)/2;
            
            if(checkPos(arr,n,k,mid)) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
        
    }
};