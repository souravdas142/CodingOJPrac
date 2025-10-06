
#define vi vector<int> 
#define vvi vector<vi>

class Solution {
public:

    int recurSol(vvi& grid, int n, int m, int robo1, int robo2, int i) {
        if(i>=n || robo1<0 || robo1>=m || robo2<0 || robo2>=m)  return 0;
        if(i==n-1) {
            int x = 0;
            int y = 0;
            if(robo1>=0 && robo1<m) x = grid[i][robo1];
            if(robo2>=0 && robo2<m && robo1!=robo2) y = grid[i][robo2];
            return x+y;
        }

        int move1 = 0, move2 = 0, move3 = 0;

        if(robo1-1>=0) {
            int x = (robo2-1>=0)?(recurSol(grid,n,m,robo1-1,robo2-1,i+1)):0;
            int y = (robo2+1<m)?(recurSol(grid,n,m,robo1-1,robo2+1,i+1)):0;
            int z = recurSol(grid, n,m, robo1-1,robo2,i+1);
            int ans = max(x,max(y,z));
            if(robo1!=robo2) ans+=(grid[i][robo1]+grid[i][robo2]);
            else ans+=(grid[i][robo1]);
            move1 = ans;

        }

        if(robo1+1<m) {
            int x = (robo2-1>=0)?(recurSol(grid,n,m,robo1+1,robo2-1,i+1)):0;
            int y = (robo2+1<m)?(recurSol(grid,n,m,robo1+1,robo2+1,i+1)):0;
            int z = recurSol(grid, n,m, robo1+1,robo2,i+1);
            int ans = max(x,max(y,z));
            if(robo1!=robo2) ans+=(grid[i][robo1]+grid[i][robo2]);
            else ans+=(grid[i][robo1]);
            move2 = ans;
        }

        if(robo1>=0 && robo1<m) {
            int x = (robo2-1>=0)?(recurSol(grid,n,m,robo1,robo2-1,i+1)):0;
            int y = (robo2+1<m)?(recurSol(grid,n,m,robo1,robo2+1,i+1)):0;
            int z = recurSol(grid, n,m, robo1,robo2,i+1);
            int ans = max(x,max(y,z));
            if(robo1!=robo2) ans+=(grid[i][robo1]+grid[i][robo2]);
            else ans+=(grid[i][robo1]);
            move3 = ans;
        }

        return max(move1,max(move2,move3));




    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int robo1 = 0, robo2 = m-1;
        int i = 0;
        return recurSol(grid,n,m, robo1, robo2, i);
    }
};