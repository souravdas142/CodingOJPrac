class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int row = mat.size();
        int col = mat[0].size();
        for(int i = 0;i<row;i++) {
            int sum = 0;
            for(int j = 0;j<col;j++) {
                sum+=mat[i][j];
            }
            if(sum==1) { // may be cleibrity
                int is_celeb = 1;
                for(int k = 0;k<row;k++) {
                    if(k==i) continue;
                    if(mat[k][i]!=1) {
                        is_celeb = 0;
                        break;
                    }
                }
                if(is_celeb==1) return i;
            }
        }
        return -1;
    }
};