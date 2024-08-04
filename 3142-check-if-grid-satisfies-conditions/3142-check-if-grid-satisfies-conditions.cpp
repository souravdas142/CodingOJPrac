class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
       for(int i = 0;i<row;i++) {
           for(int j = 0;j<col;j++) {
                int possibleRow = i+1;
                int possibleCol = j+1;
                bool check1 = false, check2 = false;
                if(possibleRow>=row) check1 = true;
                else {
                    if(grid[possibleRow][j]==grid[i][j]) check1 = true;
                    else check1 = false;
                }
                if(possibleCol>=col) check2 = true;
                else {
                    if(grid[i][possibleCol]!=grid[i][j]) check2 = true;
                    else check2 = false;
                }
                if(check1==false || check2==false) return false;

           }
       } 

       return true;
    }
};