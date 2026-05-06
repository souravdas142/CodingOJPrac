class Solution {
    public void fill(char[][] grid) {
        // Code here
        int n = grid.length;
        int m = grid[0].length;
        Deque<int[]> que = new ArrayDeque<int[]>();
        
        for(int i = 0;i<n;i++) {
            if(i==0 || i==n-1) {
                for(int j = 0;j<m;j++) {
                    if(grid[i][j]=='O') {
                        que.add(new int[]{i,j});
                        grid[i][j] = 'B';
                    }
                }
            }
            else if(grid[i][0]=='O' || grid[i][m-1]=='O') {
                if(grid[i][0]=='O') {
                    que.add(new int[]{i,0});
                    grid[i][0] = 'B';
                }
                if(grid[i][m-1]=='O') {
                    que.add(new int[]{i,m-1});
                    grid[i][m-1] = 'B';
                }
            }
        }
        
        int[] dx = {0,1,0,-1};
        int[] dy = {1,0,-1,0};
        
        while(que.isEmpty()!=true) {
            int[] node = que.poll();
            for(int i = 0;i<4;i++) {
                int x = node[0]+dx[i];
                int y = node[1]+dy[i];
                if(x>=0 && x<n && y>=0 && y<m && grid[x][y]=='O') {
                    grid[x][y] = 'B';
                    que.add(new int[]{x,y});
                }
            }
        }
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j]=='O') {
                    grid[i][j] = 'X';
                }
            }
        }
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j]=='B') {
                    grid[i][j] = 'O';
                }
            }
        }
        
    }
}
