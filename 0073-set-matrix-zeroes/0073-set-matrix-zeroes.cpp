class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int> > matrix2 = matrix;

        for(int i = 0;i<row;i++) {
            for(int j = 0;j<col;j++) {
                if(matrix2[i][j]==0) {
                    for(int k = 0;k<col;k++) {
                        matrix[i][k] = 0;
                    }
                    for(int k = 0;k<row;k++) {
                        matrix[k][j] = 0;
                    }
                    
                }
            }
        }
        
    }
};