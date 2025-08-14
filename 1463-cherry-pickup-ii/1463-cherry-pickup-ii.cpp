#define vi vector<int>
#define vvi vector<vi>

class Solution {
public:
    vi dirx = {-1,0,1};
 
    int roboRecurSolve(vvi& grid, int n, int m, int index, int robo1, int robo2) {


        if((robo1<0 || robo1>=m) || (robo2<0 || robo2>=m)) return -1e8;

        if(index==n-1) {
            if(robo1==robo2) return grid[index][robo1];
            return grid[index][robo1]+grid[index][robo2];
        }

        

        int maxi = INT_MIN;

        for(int i = 0;i<3;i++) {
            for(int j = 0;j<3;j++) {
                if(robo1 == robo2) {
                    maxi = max(maxi,grid[index][robo1]+roboRecurSolve(grid,n,m,index+1,robo1+dirx[i],robo2+dirx[j]));
                }
                else {
                    maxi = max(maxi,grid[index][robo1]+grid[index][robo2]+roboRecurSolve(grid,n,m,index+1,robo1+dirx[i],robo2+dirx[j]));
                }
            }
        }
        return maxi;
    }
    int recurSol(vvi& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int index = 0;
        int rob1 = 0, rob2 = m-1;
        return roboRecurSolve(grid,n,m,index,rob1, rob2);
    }
    int cherryPickup(vector<vector<int>>& grid) {
        return recurSol(grid);
    }
};