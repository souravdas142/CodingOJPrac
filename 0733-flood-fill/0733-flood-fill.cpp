#define vvi vector<vector<int> >
#define vi vector<int> 
#define vvb vector<vector<bool> >
#define vb vector<bool>
#define pi pair<int,int>

vector<int> dx = {0,0,1,-1};
vector<int> dy = {1,-1,0,0};

class Solution {
    bool checkPossible(pi cell,vvb& visited,vvi& image,int initColor,int m,int n) {
        int x = cell.first;
        int y = cell.second;
        if(x>=0 && y>=0 && x<m && y<n && image[x][y]==initColor && !visited[x][y]) return true;
        return false;
    }
private:
    void bfs(vvi& image,vvb& visited,pi startCell,int color,int m,int n) {

        int initColor = image[startCell.first][startCell.second];
        visited[startCell.first][startCell.second] = true;
        deque<pi> dq;
        dq.push_back(startCell);

        while(!dq.empty()) {
            pi u = dq.front();
            dq.pop_front();
            image[u.first][u.second] = color;

            for(int i = 0;i<4;i++) {
                pi v(u.first+dx[i],u.second+dy[i]);
                if(checkPossible(v,visited,image,initColor,m,n)) {
                    visited[v.first][v.second] = true;
                    dq.push_back(v);
                }
            }
        }

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int m = image.size();
        int n = image[0].size();

        
        pi cell(sr,sc);

        vvb visited(m,vb(n,false));

        bfs(image,visited,cell,color,m,n);

        return image;
        
    }
};