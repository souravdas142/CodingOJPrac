class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        int left = 0, right = m-1;
        int row = 0;
        while(left<right) {
            int mid=left+(right-left)/2;

            int maxEle = 0;
            row = 0;
            for(int i = 0;i<n;i++) {
                if(mat[i][mid]>maxEle) {
                    maxEle = mat[i][mid];
                    row = i;
                }
            }

            if(mat[row][mid]>mat[row][mid+1]) {
                right = mid;
            }
            else {
                left=mid+1;
            }

        }
        return {row,left};
        
    }
};