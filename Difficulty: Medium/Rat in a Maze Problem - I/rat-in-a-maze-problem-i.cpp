//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

#define vvi vector<vector<int> >
#define vs vector<string> 
#define vvb vector<vector<bool> >

class Cell {
    public:
    int row,col;
    Cell():row(0),col(0) {}
    Cell(int x,int y):row(x),col(y) {}
};

vector<int> dx = {1,0,0,-1};
vector<int> dy = {0,1,-1,0};

class Solution {
    bool checkPossible(int row, Cell cell,vvb& visited,vvi& maze) {
        
        if(cell.row>=0 && cell.col>=0 && cell.row<row && cell.col<row && visited[cell.row][cell.col]!=true && maze[cell.row][cell.col]!=0) return true;
        return false;
        
    }
  public:
  
    void solve(vvi& maze, vvb& visited,Cell cell,int row, string result,vs& ans) {
        
        if(cell.row>=row-1 && cell.col>=row-1) { //n*n matrix row == col
            ans.push_back(result);
            return;
        }
        
        for(int i = 0;i<4;i++) {
            
            Cell newCell(cell.row+dx[i],cell.col+dy[i]);
            
            if(checkPossible(row,newCell,visited,maze)) {
                
                visited[newCell.row][newCell.col] = true;
                
                if(i==0) result.push_back('D');
                else if(i==1) result.push_back('R');
                else if(i==2) result.push_back('L');
                else if(i==3) result.push_back('U');
                solve(maze,visited,newCell,row,result,ans);
                result.pop_back();
                visited[newCell.row][newCell.col] = false;
                
            }
            
            
        }
        
    }
  
    vector<string> findPath(vector<vector<int>> &maze) {
        // Your code goes here
        vs ans;
        int row = maze.size();
        if(row == 0) return ans;
        if(maze[0][0]==0) return ans;
        vvb visited(row,vector<bool>(row,false));
        
        string result;
        Cell cell;
        visited[cell.row][cell.col] = true;
        solve(maze,visited,cell,row,result,ans);
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends