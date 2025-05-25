// User function template for C++

class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int row = mat.size();
        int col = mat[0].size();
        int med = (row*col+1)/2;

        // The idea is max is mat[row-1][col-1]
        // min is mat[0][0]
        // so the median will lies on this range....
        // suppose here for 1st example, range 1~9 then mid is
        // 1+(9-1)/2 = 5 now, see how many elements are there lesser 
        // than this value.... 
        // so if 5 is median then number of elements on the left == righ to 5
     
        int high = INT_MIN;
        int low = INT_MAX;
        
        
        
        for(int i = 0;i<row;i++) {
            high = max(high,mat[i][col-1]);
            low = min(low,mat[i][0]);
        }
        
        
        while(low<high) {
            int mid = low+(high-low)/2;
            int cnt = 0;
            
            for(int i = 0;i<row;i++) {
                cnt+=upper_bound(mat[i].begin(),mat[i].begin()+col,mid) - mat[i].begin();
                
            }
            
            if(cnt>=med) {
                high = mid;
            }
            else {
                low = mid+1;
            }
           
            
            
        }
        
        return high;
        
        
    }
};
