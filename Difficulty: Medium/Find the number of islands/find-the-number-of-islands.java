class Solution {
    
    public boolean check(char[][] grid, boolean[][] visited, int vr, int vc) {
        int n = grid.length;
        int m = grid[0].length;
        
        if(vr>=0 && vr<n && vc>=0 && vc<m && visited[vr][vc]!=true && grid[vr][vc]=='L') {
            return true;
        }
        return false;
    }
    
    public void bfs(char[][] grid,int sr, int sc,  boolean[][] visited) {
        int[] dx = {0,1,-1,0,1,-1,1,-1};
        int[] dy = {1,0,0,-1,1,1,-1,-1};
        visited[sr][sc] = true;
        
        Deque<int[]> que = new ArrayDeque<>();
        
        que.add(new int[]{sr,sc});
        
        while(que.isEmpty()!=true) {
            int[] node = que.poll();
            int ur = node[0];
            int uc = node[1];
            for(int i = 0;i<8;i++) {
                int vr = ur+dx[i];
                int vc = uc+dy[i];
                if(check(grid,visited,vr,vc)) {
                    visited[vr][vc] = true;
                    que.add(new int[]{vr,vc});
                }
            }
        }
        
        
        
        
        
        
    }
    public int countIslands(char[][] grid) {
        // Code here
        int n = grid.length;
        int m = grid[0].length;
        boolean[][] visited = new boolean[n][m];
        int ans = 0;
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j] == 'L' && visited[i][j]!=true) {
                    visited[i][j] = true;
                    ans++;
                    bfs(grid,i,j,visited);
                }
            }
        }
        
        
        return ans;
    }
}