class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
// Bruteforce
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0;i<row;i++) {
            for(int j= 0;j<col;j++) {
                // O(n^2)
                if(matrix[i][j]==0) {
                    
                    for(int k = 0;k<col;k++) {
                        if(matrix[i][k]==0) continue;
                        matrix[i][k] = -1;
                    }
                    for(int k = 0;k<row;k++) {
                        if(matrix[k][j]==0) continue;
                        matrix[k][j] = -1;
                    }
                }
            }
        }
        for(int i = 0;i<row;i++) {
            for(int j = 0;j<col;j++) {
                if(matrix[i][j]==-1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};