class Solution {
private:

    bool checkValidity(int col, int row,int n,vector<bool> &uprightHash,vector<bool>& upleftHash,vector<bool>& rowHash) {

        if(row<n && col<n && rowHash[row]==false && uprightHash[((n-1)+(col-row))]==false && upleftHash[(col+row)]==false) return true;

        
        return false;
    }

    void nqueens(vector<string>& board,int n,int indexcol, vector<vector<string> >& ans,vector<bool> uprightHash,vector<bool> upleftHash,vector<bool> rowHash) {
        
        if(indexcol>=n) {
            ans.push_back(board);
            return;
        }
        
        /*

            1) there is one queen in each row
            2) They are not under attack when there is not other queens
                placed to their diagonal
            3)there is only one single queens in each column

        */

        for(int row = 0;row<n;row++) {

            if(checkValidity(indexcol,row,n,uprightHash,upleftHash,rowHash)) {

                // we can able to place the queens in the current row
                // so try for the next row
                board[row][indexcol] = 'Q';
                uprightHash[((n-1)+(indexcol-row))] = true;
                upleftHash[(indexcol+row)] = true;
                rowHash[row] = true;
                nqueens(board,n,indexcol+1,ans,uprightHash,upleftHash,rowHash);
                board[row][indexcol] = '.';
                uprightHash[((n-1)+(indexcol-row))] = false;
                upleftHash[(indexcol+row)] = false;
                rowHash[row] = false;
                
            }

        }

    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        int indexcol = 0;
        vector<bool> uprightHash((2*n)-1),upleftHash((2*n)-1),rowHash(n);
        vector<vector<string> > ans;
        nqueens(board,n,indexcol,ans,uprightHash,upleftHash,rowHash);
        return ans;
        
    }
};