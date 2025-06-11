#define vs vector<string> 
#define vvs vector<vs >

#define vi vector<int>


class Solution {
public:
    bool checkPossible(int n, int m,int row, int col,vi& rightUpHash, vi& leftUpHash, vi& colHash) {
        if(row>=0 && col>=0 && row<n && col<m && rightUpHash[row+col]!=1 && leftUpHash[(n-1)+(row-col)]!=1 && colHash[col] !=1 ) return true;
        return false;
    }
    void solve(vs board,int row, vi rightUpHash, vi leftUpHash, vi colHash,vvs& ans, vs res, string s) {
        
        int n = board.size();
        int m = board[0].size();

        if(row>=n) {
            ans.push_back(board);
            return;
        }

        for(int col = 0;col<m;col++) {
            if(checkPossible(n,m,row,col,rightUpHash,leftUpHash,colHash)) {
                rightUpHash[row+col] = 1;
                leftUpHash[(n-1)+(row-col)] = 1;
                colHash[col] = 1;
                board[row][col] = 'Q';
                solve(board,row+1,rightUpHash,leftUpHash,colHash,ans,res,s);
                board[row][col] = '.';
                rightUpHash[row+col] = 0;
                leftUpHash[(n-1)+(row-col)] = 0;
                colHash[col] = 0;
            }
        }



    }
    vector<vector<string>> solveNQueens(int n) {

        vs board(n,string(n,'.'));
        vector<int> rightUpHash(n+n,0), leftUpHash(n+n,0), colHash(n,0);
        vvs ans;
        vs res;
        string s = "";
        int row = 0;

        solve(board,row,rightUpHash,leftUpHash,colHash,ans,res,s);

        return ans;
        
    }
};