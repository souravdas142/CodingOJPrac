#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
    int recurSolve(const vvi& matrix, int i, int j, int n, int m, vvi& dp) {
        if (i == n - 1) return matrix[i][j];  // Base case: last row
        if (dp[i][j] != INT_MAX) return dp[i][j];  // Already computed

        int minPath = recurSolve(matrix, i + 1, j, n, m, dp);  // Down
        if (j > 0) minPath = min(minPath, recurSolve(matrix, i + 1, j - 1, n, m, dp));  // Down-left
        if (j < m - 1) minPath = min(minPath, recurSolve(matrix, i + 1, j + 1, n, m, dp));  // Down-right

        return dp[i][j] = minPath + matrix[i][j];
    }

    int minFallingPathSum(vvi& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vvi dp(n, vi(m, INT_MAX));  // Initialize with INT_MAX to track uncomputed states

        int ans = INT_MAX;
        for (int j = 0; j < m; ++j) {
            ans = min(ans, recurSolve(matrix, 0, j, n, m, dp));
        }
        return ans;
    }
};