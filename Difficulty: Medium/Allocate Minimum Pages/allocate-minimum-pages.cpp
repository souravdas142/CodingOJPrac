class Solution {
  public:
    int checkPossible(vector<int>& arr, int maxStudents, int maxPages) {
       
        int student = 1;
        
        int n = arr.size();
        int pages = 0;
        
        for(int i = 0;i<n;i++) {
            pages+=arr[i];
            if(pages>maxPages) {
                student++;
                pages = arr[i];
                
            }
            if(student>maxStudents) return false;
        }
        
        return true;
        
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int low = INT_MIN;
        int high = 0;
        if(k>n) return -1;
        
        for(int i = 0;i<n;i++) {
           
            high += arr[i];
            low = max(low,arr[i]);
        }
        
        int ans = -1;
        
        while(low<=high) {
            int mid = low+(high-low)/2;
            
            if(checkPossible(arr,k,mid)) {
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