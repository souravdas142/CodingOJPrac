#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
    int recurSolve(vvi& matrix, int i, int j, int n, int m, vvi& dp) {
        if (i >= n) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        int mini = recurSolve(matrix, i+1, j, n, m, dp);
        if (j-1 >= 0) mini = min(mini, recurSolve(matrix, i+1, j-1, n, m, dp));
        if (j+1 < m) mini = min(mini, recurSolve(matrix, i+1, j+1, n, m, dp));
        
        return dp[i][j] = mini + matrix[i][j];
    }
    
    int recurSol(vvi& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        // Early return for single row case
        if (n == 1) {
            return *min_element(matrix[0].begin(), matrix[0].end());
        }
        
        vvi dp(n, vi(m, -1));
        int ans = INT_MAX;
        
        for (int j = 0; j < m; j++) {
            ans = min(ans, recurSolve(matrix, 0, j, n, m, dp));
        }
        
        return ans;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        return recurSol(matrix);
    }
};