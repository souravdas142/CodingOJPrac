class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        
        vector<int> ans;
        int row = mat.size();
        int col = mat[0].size();
        int top = 0, bottom = row-1, left = 0, right = col-1;
        
        // print top
        while(left<=right || top<=bottom) {
            
            int k = left;
            if(top<=bottom) {
                while(k<=right) {
                    ans.push_back(mat[top][k]);
                    //cout<<mat[top][k];
                    k++;
                }
                top++;
            }
            // printing right side
            k=top;
            if(left<=right) {
                while(k<=bottom) {
                    ans.push_back(mat[k][right]);
                    //cout<<mat[k][right];
                    k++;
                }
                right--;
            }
            
            k = right;
            // printing bottom
            if(top<=bottom) {
                while(k>=left) {
                    ans.push_back(mat[bottom][k]);
                    //cout<<mat[bottom][k];
                    k--;
                }
                bottom--;
            }
            
            k=bottom;
            // printing left
            if(left<=right) {
                while(k>=top) {
                    ans.push_back(mat[k][left]);
                    //cout<<mat[left][k];
                    k--;
                }
                left++;
            }
        }
        return ans;
        
        
    }
};