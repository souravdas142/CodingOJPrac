#define vvi vector<vector<int> >
class Solution {
    int fupb(vvi& matrix,int target) {
        int row = matrix.size();
        int low = 0, high = row;
        while(low<high) {
            int mid = low+(high-low)/2;
            if(matrix[mid][0]>target) {
                high = mid;
            }
            else {
                low = mid+1;
            }
        }
        return low;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int upb = fupb(matrix,target);
        cout<<upb<<endl;
        int rpos = -1;
        if(upb==row-1) {
            if(target<=matrix[row-1][col-1] && target>=matrix[row-1][0]) {
                rpos = upb;
            }
            else if(row-2>=0 && target<=matrix[row-2][col-1] && target>=matrix[row-2][0]) {
                rpos = upb-1;
            }
            else {return false;}
            
            
        }
        if(target<matrix[0][0]) return false;
        rpos = upb-1;
        int low = 0,high = col-1;
        while(low<=high) {
            int mid = low+(high-low)/2;
            if(matrix[rpos][mid]==target) return true;
            else if(matrix[rpos][mid]>target) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }

        return false;
        
    }
};