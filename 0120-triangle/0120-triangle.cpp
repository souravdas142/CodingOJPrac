
#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
    int recurSol(vvi& triangle, int n, int i, int j) {

        if(i==n-1 || j==n-1) return triangle[i][j];
        

        
        int x = triangle[i][j]+recurSol(triangle,n, i+1, j);
        int y = triangle[i][j]+recurSol(triangle,n,i+1,j+1);
        
        return min(x,y);
    }

    int memoSol(vvi& triangle, int n, int i, int j, vvi& dp) {

        if(i==n-1 || j==n-1) return dp[i][j] = triangle[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];

        
        int x = triangle[i][j]+memoSol(triangle,n, i+1, j,dp);
        int y = triangle[i][j]+memoSol(triangle,n,i+1,j+1,dp);
        
        return dp[i][j] = min(x,y);
    }


    int tabuSol(vvi& triangle, int n) {
        int m = triangle[n-1].size();

        vvi dp(n,vi(m,0));
        
        for(int i = 0;i<m;i++) {
            dp[n-1][i] = triangle[n-1][i];
        }

        for(int i = n-2;i>=0;i--) {
            int k = triangle[i].size();

            for(int j = 0;j<k;j++) {
                int x = triangle[i][j]+dp[i+1][j];
                int y = triangle[i][j]+dp[i+1][j+1];

                dp[i][j] = min(x,y);
            }
        }

        return dp[0][0];

    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vvi dp(n,vi(m,-1));

        // return recurSol(triangle,n,0,0);
        // return memoSol(triangle,n,0,0,dp);
        return tabuSol(triangle,n);
    }
};