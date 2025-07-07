class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
        // kth smallest element is x
        // how many numbers in between matrix[0][0] to x
        
        int ans = 0;
        int numbers = 0;
        int low = matrix[0][0];
        int n = matrix.size();
        int m = matrix[0].size();
        int high = matrix[n-1][m-1];
        
        
        while(low<=high) {
            int mid = low+(high-low)/2;
            numbers = 0;
            
            for(int i = 0;i<n;i++) {
                numbers+=(upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin());
                if(numbers>=k) break;
            }
            
            if(numbers>=k) {
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