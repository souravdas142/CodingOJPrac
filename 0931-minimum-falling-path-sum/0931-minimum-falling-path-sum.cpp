#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
    int recurSolve(vvi& matrix,int i, int j, int n, int m,vvi& dp) {
        if(i>=n) {
            return 0;
        }
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int mini = INT_MAX;
        if(j-1>=0) mini = min(mini,recurSolve(matrix,i+1,j-1,n,m,dp)+matrix[i][j]);
        if(j+1<m) mini = min(mini,recurSolve(matrix,i+1,j+1,n,m,dp)+matrix[i][j]);
        mini = min(mini,recurSolve(matrix,i+1,j,n,m,dp)+matrix[i][j]);
        return dp[i][j] =  mini;
    }
    int recurSol(vvi& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = INT_MAX;
        vvi dp(n,vi(m,INT_MAX));
        for(int i = 0;i<m;i++) {
            
            ans = min(ans,recurSolve(matrix,0,i,n,m,dp));
        }
        return ans;
    }

    int tabuSol(vvi& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vvi dp(n,vi(m,0));
        dp[0] = matrix[0];
        for(int i = 1;i<n;i++) {
            for(int j = 0;j<m;j++) {
                int mini = matrix[i][j]+dp[i-1][j];
                if(j-1>=0) mini = min(mini,matrix[i][j]+dp[i-1][j-1]);
                if(j+1<m) mini = min(mini,matrix[i][j]+dp[i-1][j+1]);
                dp[i][j] = mini;
            }
        }
        int ans = INT_MAX;
        for(int i = 0;i<m;i++) {
            ans = min(ans,dp[n-1][i]);
        }
        return ans;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        //return recurSol(matrix);
        return tabuSol(matrix);
        
    }
};