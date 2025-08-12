
#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
    int recurSolve(vvi& triangle, int n, int i, int j,vvi& dp) {
        
        if(i>=n) {
            return 0;
        }
        if(j>=triangle[i].size()) {
            return 0;
        }
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        int way1 = triangle[i][j]+recurSolve(triangle,n,i+1,j,dp);
        int way2 = triangle[i][j]+recurSolve(triangle,n,i+1,j+1,dp);
        return dp[i][j] = min(way1,way2);
    }
    int recurSol(vvi& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vvi dp(triangle);
        for(auto &row: dp) {
            fill(row.begin(),row.end(),INT_MIN);
        }
        
        return recurSolve(triangle,n,0,0,dp);
    }
    int minimumTotal(vector<vector<int>>& triangle) {

        return recurSol(triangle);
        
    }
};