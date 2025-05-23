class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();
        int has_col = 0;
        for(int i = 0;i<row;i++) {
            if(matrix[i][0]==0) has_col = 1;
            for(int j = 1;j<col;j++) {
                if(matrix[i][j]==0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i = row-1;i>=0;i--) {
            for(int j = col-1;j>=0;j--) {
                if(matrix[i][0] == 0 || matrix[0][j]==0) {
                    matrix[i][j] = 0;
                }
            }
            if(has_col == 1 ) {
                matrix[i][0] = 0;
            }
        }
        
    }
};