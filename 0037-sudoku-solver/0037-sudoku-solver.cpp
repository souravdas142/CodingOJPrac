#define vvc vector<vector<char> >
class Solution {
private:
    bool solve(vvc& board) {
        int n = board.size();
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) { /// traverse the board

                if(board[i][j]=='.') { /// We got a blank cell, lets try to fill

                    for(char c = '1'; c<='9'; c++) { // we can fill the board with 0 to 9 try all of them one by one

                        if(isPossible(c,board,i,j)) { // if it is possible to fill try for the next blank cell
                            board[i][j] = c;
                            if(solve(board) == true) { /// If we can fill the board with success return true; no need to call further
                                return true;
                            }
                            else {
                                board[i][j] = '.';

                            }
                        }

                    }
                    return false; /// we tried all the possibilities but still can't able to fill with one

                }

            } /// end of traverse the board left to rigt
        }   /// end of traverse the board up to down
        return true;  // we travered all the board and still not found false then it must be true
    }
    bool isPossible(char c,vvc& board,int row,int col) {
        for(int i = 0;i<9;i++) {

            if(board[i][col] == c) return false; // check every row of he same col
            if(board[row][i] == c) return false; // check every col of the same row



            if(board[((3*(row/3))+(i/3))][(3*(col/3))+(i%3)]==c) return false;


        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {

        solve(board);
        
    }
};