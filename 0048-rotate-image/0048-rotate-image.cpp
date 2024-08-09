class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int sz  = matrix.size();
        for(int i = 0;i<sz-1;i++) {
            for(int j = i+1;j<sz;j++) {
                swap(matrix[j][i],matrix[i][j]);
            }
        }

        for(int i= 0;i<sz;i++) {
            int j = sz- 1,k= 0;
            while(k<=j) {
                swap(matrix[i][k],matrix[i][j]);
                k++;j--;
            }
        }
        
    }
};