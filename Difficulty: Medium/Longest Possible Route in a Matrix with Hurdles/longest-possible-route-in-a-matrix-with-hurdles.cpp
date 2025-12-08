// User function Template for C++
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>


vector<int> dx = {0,0,1,-1};
vector<int> dy = {1,-1,0,0};

class Solution {
  public:
    int checkValid(vvi& matrix, int n, int m, vvb& mark, int x, int y,int xd, int yd) {
      
        if(x>=0 && x<n && y>=0 && y<m && mark[x][y]==false && matrix[x][y]==1) {
            return true;
        }
        return false;
    }
    void solve(vvi& matrix, int n, int m, int xs, int ys, int xd, int yd, vvb mark, int len, int& ans) {
        if(xs == xd && ys==yd) {
            
            ans = max(ans,len);
            return;
        }
        
        for(int i = 0;i<4;i++) {
            int newx = xs+dx[i];
            int newy = ys+dy[i];
            
            if(checkValid(matrix,n,m,mark,newx,newy,xd,yd)) {
                
                mark[newx][newy] = true;
                solve(matrix,n,m,newx,newy,xd,yd,mark,len+1,ans);
                mark[newx][newy] = false;
                
            }
        }
        
        
    }
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd) {
        // code here
        if(matrix[xs][ys]==0) return -1;
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<bool>> mark(n,vb(m,false));
        
        int ans = -1;
        int len = 0;
        mark[xs][ys] = true;
        
        solve(matrix,n,m,xs,ys,xd,yd,mark,len,ans);
        
        return ans;
        
    }
};