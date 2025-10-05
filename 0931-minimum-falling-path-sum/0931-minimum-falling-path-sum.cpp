#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
    int recurSol(vvi& matrix, int n, int row, int col) {
        if(row==0 && col>=0 && col<n) return matrix[row][col];
        if(row<0 || col<0 || col>=n) return INT_MAX;

        int x = recurSol(matrix,n,row-1,col);
        int y = recurSol(matrix,n,row-1,col-1);
        int z = recurSol(matrix,n,row-1,col+1);

        int ans = min(x,min(y,z));

        return (matrix[row][col]+ans);
    }
    int memoSol(vvi& matrix, int n, int row, int col,vvi& dp) {
        if(row==0 && col>=0 && col<n) return matrix[row][col];
        if(row<0 || col<0 || col>=n) return INT_MAX;

        if(dp[row][col]!=INT_MAX) return dp[row][col];

        int x = memoSol(matrix,n,row-1,col,dp);
        int y = memoSol(matrix,n,row-1,col-1,dp);
        int z = memoSol(matrix,n,row-1,col+1,dp);

        int ans = min(x,min(y,z));

        return dp[row][col] = (matrix[row][col]+ans);
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int row = n-1;
        int col = n-1;
        int ans = INT_MAX;

        // for(int i = 0;i<n;i++) {
        //     ans = min(ans,recurSol(matrix, n, row, col-i));
        // }

        vvi dp(n,vi(n,INT_MAX));

        for(int i = 0;i<n;i++) {
            ans = min(ans,memoSol(matrix, n, row, col-i,dp));
        }  

        return ans;
    }
};