class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int low = 0;
        int high = n-1;
        int ans = 0;
        while(low<=high) {
            int mid = low+(high-low)/2;
            if(matrix[mid][0]<=target) {
                ans = mid;
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        //cout<<ans<<"dff"<<high<<"djfjd"<<low<<endl;

        low = 0, high = matrix[ans].size()-1;
        int ans2 = 0;

        while(low<high) {
            int mid = low+(high-low)/2;
            if(matrix[ans][mid]>=target) {
                high = mid;
            }
            else {
                low = mid+1;
            }
        }

        if(matrix[ans][high]!=target) return false;
        

        return true;
    }
};